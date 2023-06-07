/*
 Knapsack problem on spoj: http://www.spoj.com/problems/KNAPSACK/

*/

#include<iostream>
#include<vector>
#include<map>
#include<cstring>


using namespace std;

int main(){

   int S,n;
   cin>>S>>n;

   int a[n+1],v[n+1];

   for(int i=1;i<=n;i++){
        cin >> a[i] >> v[i];
    }

    long dp[n+1][S+1];

    memset(dp, 0, sizeof(dp));

    
    for(int i=1;i<=S;i++){
        for(int j=1;j<=n;j++){
             dp[j][i] = dp[j-1][i];
             if(i>=a[j]) dp[j][i] = max(dp[j][i], v[j] + dp[j-1][i-a[j]]);
          } 
    }

    
    cout << dp[n][S];


   return 0;
}