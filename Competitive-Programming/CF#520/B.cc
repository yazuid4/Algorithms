#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bitset>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;

int n;

int LPF[1000007];

    void least_prime_factor(){

              for(int i=2; i*i <= n;i++){

                     if(LPF[i]==0){

                          LPF[i]=i;

                          for(int j=i+i; j <= n; j+=i){
                               if(LPF[j]==0)
                                     LPF[j]=i;
                              }
                         }
                    }
              }


     vector<int> getPrimeFactorization(int x){

                    int tp = x;

                    vector<int> v;

                    while(tp!=1){
                            v.push_back(LPF[tp]);
                            tp = tp / LPF[tp];
                         }

                    return v;
               }





int main(){

     
     cin >> n;

     if(n == 1){
         cout << 1 << " " << 0;
         return 0;
     }

     least_prime_factor();

     for(int i = 1; i <= n; i++){
         if(!LPF[i])
             LPF[i] = i;
        }
     
     vector<int> p = getPrimeFactorization(n);
     set<int> st;


     for(int i = 0; i < p.size(); i++){
           st.insert(p[i]);
         }
     
     
     int cnt = 0;   
     int px = 0;
     map<LL,LL> mpx;


     for(int i = 0; i < p.size(); i++){
            mpx[p[i]]++;

            if(mpx[p[i]] > px){
                 px = mpx[p[i]];
               }
          }
     
     

     if((px & (px-1)) != 0){
          //power of 2 that is close to px
          int as;

          for(int b = 30; b > 0; b--){
               if(px > (1 << b)) break;
               as = (1 << b);  
               }
          
          cnt++;
          px = as;
         
      }
     else{
          if(p.size() != px * st.size()){
              cnt++;
           }
      }
      

     int bset = 0;

     while(px != 1){
         px = px/2;
         bset++;
       }
      
      
     cnt += bset;
  
     
     LL ans = 1;

     for(set<int>::iterator it = st.begin(); it != st.end(); it++){
                 LL el = (LL) *it;
                 ans =  ans * el;

                 if(ans >= n){
                      break;
                   }
               }
      
      if(ans >= n)
          cout << n << " " << 0;
      else
         cout << ans << " " << cnt;
      
     
     
    return 0;
  }