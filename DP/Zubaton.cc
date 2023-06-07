/*
    Question link: https://cf17-final.contest.atcoder.jp/tasks/cf17_final_d
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<limits>
#include<cmath>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;

const int MX = numeric_limits<int>::max();

struct par{
    int h;
    int p;
}v[5005];


bool cmp(par a, par b){
          return a.h + a.p < b.h + b.p; 
       }

int dp[5005][5005];



int main(){
    
    int n, ans = 0;
    cin >> n;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
                 dp[i][j] = MX;


    for(int i = 1; i <= n; i++){
         cin >> v[i].h >> v[i].p;
      }
    
    sort(v + 1, v + n + 1, cmp);

    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
             
               dp[i][j] = dp[i-1][j];
               
               if(dp[i-1][j-1] <= v[i].h){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + v[i].p);
                 }
           }
        } 

    
    for(int j = 1; j <= n; j++) if(dp[n][j] != MX) ans = j;

    
    cout << ans;
    
    

 

     
    return 0;
  }

