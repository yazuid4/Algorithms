/*
 Problem link: http://codeforces.com/contest/799/problem/C
*/

#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

const int mx = 1e5+2;
int n,c,d;
vector<pair<int, pair<int,char> > > p;

           
      bool  compaire(const pair<int, pair<int,char> > &a, const pair<int, pair<int,char> > &b){
                          return (a.first > b.first) ;    
                  }


               int solve(int l,int r, int cc,int dd){
                      
                      if(l>r) return 0;
                      
                      int m = (l+r)/2;
                      int k=0;

                      if(p[m].second.second=='C'){
                           if(cc>=p[m].second.first){
                                //I can buy
                                k=p[m].first;
                                k = max(k,solve(l,m-1,cc,dd));
                           }else{
                                //k = max(solve(l,m-1,cc,dd),solve(m+1,r,cc,dd));
                                k = solve(l,m-1,cc,dd);
                                   if(k==0){
                                       k=solve(m+1,r,cc,dd);
                                   }
                           }
                      }
                      else{
                               if(dd>=p[m].second.first){
                                 //I can buy
                                 k=p[m].first;
                                 k = max(k,solve(l,m-1,cc,dd));
                               }else{
                                   //k = max(solve(l,m-1,cc,dd),solve(m+1,r,cc,dd));
                                   k = solve(l,m-1,cc,dd);
                                   if(k==0){
                                       k=solve(m+1,r,cc,dd);
                                   }
                               }
                        }

                     return k;
                 }                  

      

        
int main(){

     ios::sync_with_stdio(false);
    
     cin>>n>>c>>d;


     for(int i=0;i<n;i++){
         pair<int,char> pr;int tmp;
         cin>>tmp>>pr.first>>pr.second;
         p.push_back(make_pair(tmp,pr));
       }

     sort(p.begin(), p.end(), compaire);


     int res=0;

     for(int i=0;i<n-1;i++){
          
        int re=p[i].first;int cc=c,dd=d;

        if(p[i].second.second=='C')
             {cc-=p[i].second.first;}
        else
             {dd-=p[i].second.first;}
        
        if(dd>=0&&cc>=0){
                int k = solve(i+1,n-1,cc,dd);
            if(k){
                res = max(res,re + k);
              }
          }
          
      }

     
     cout << res;

    return 0;
}