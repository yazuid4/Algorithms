/*
  Link: https://www.spoj.com/problems/ABCPATH/
  DFS +  Memostation
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

int n, m;
char mat[55][55];
int dp[55][55][55];

          
        int DFS(int i, int j, int p){
                 
                 if(dp[i][j][p] != -1)
                       return dp[i][j][p];

                 
                 int res = 0;

                 if(i > 0){
                        if(p == (mat[i-1][j]-'0')-1){
                              res = max(res, 1 + DFS(i-1,j,p+1));
                            }
                        if(j > 0 && (p == (mat[i-1][j-1]-'0')-1)){
                              res = max(res, 1 + DFS(i-1,j-1,p+1));
                           } 
                        if(j < m-1 && (p == (mat[i-1][j+1]-'0')-1)){
                              res = max(res, 1 + DFS(i-1,j+1,p+1));
                           }                        
                       }

                 if(i < n-1){
                        if(p == (mat[i+1][j]-'0')-1){
                              res = max(res, 1 + DFS(i+1,j,p+1));
                           }
                        if(j > 0 && (p == (mat[i+1][j-1]-'0')-1)){
                              res = max(res, 1 + DFS(i+1,j-1,p+1));
                           } 
                        if(j < m-1 && (p == (mat[i+1][j+1]-'0')-1)){
                              res = max(res, 1 + DFS(i+1,j+1,p+1));
                           }                        
                     }   

                 if(j > 0){
                     if(p == (mat[i][j-1]-'0')-1){
                              res = max(res, 1 + DFS(i,j-1,p+1));
                           }
                       }

                 if(j < m-1){
                     if(p == (mat[i][j+1]-'0')-1){
                              res = max(res, 1 + DFS(i,j+1,p+1));
                           }
                        }


                 return (dp[i][j][p] = res); 

                }


int main(){
    

    int t;


    while(true){

        
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        t++;

        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                  cin >> mat[i][j];
               }
            }
    
        int ans = 0;
        bool ck = false;

    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 if(mat[i][j] == 'A'){
                        ck = true;
                        int p = ('A' - '0');
                        ans = max(ans, DFS(i,j,p));
                     }
               }
            }
    

        if(ck)
          cout << "Case " << t << ": " <<  ans+1 << "\n";
        else
          cout << "Case " << t << ": " <<  0 << "\n";
    
    }

    
    return 0;
 }

