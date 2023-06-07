/*
 Question link : "https://www.spoj.com/problems/PT07X/"
 Minimum size vertex-cover for trees

*/

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second

using namespace std;

vector<int> v[100005];
int dp[100005][2];


     int calc_siz_vertex(int i, int t, int p){
               
           
            if(v[i].size() == 0) return 0;
            
            if(dp[i][t] != -1) return dp[i][t];

            
            int res = 0;


            if(t == 1){
                res += 1;

                 for(int j = 0; j < v[i].size(); j++){
                        if(v[i][j] != p){
                             res += min(calc_siz_vertex(v[i][j], 0, i), calc_siz_vertex(v[i][j], 1, i));
                          }
                     }
              }
            else{
                for(int j = 0; j < v[i].size(); j++){
                        if(v[i][j] != p){
                             res += calc_siz_vertex(v[i][j], 1, i);
                          }
                     }
             }

            
            return (dp[i][t] = res);
  
           }


int main(){

    int n;
    cin >> n;

    int root = 1, mx = 0;

    for(int i = 0; i < n-1; i++){
          int x, y;
          cin >> x >> y;

          v[x].pb(y);
          v[y].pb(x);

          if(v[x].size() > mx){
               root = x;
               mx = v[x].size();
            }
          if(v[y].size() > mx){
               root = y;
               mx = v[y].size();
            }
        }
    

    memset(dp, -1, sizeof dp);
    cout << min(calc_siz_vertex(root, 0, -1), calc_siz_vertex(root, 1, -1));


    return 0;
 }

