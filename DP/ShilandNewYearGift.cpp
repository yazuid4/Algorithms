/*
 Problem: Shil and New Year Gift (Hackerearth)
 Dp + Bitmasking
*/

#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

int n;
int a[20];
int dp[20][1<<15];


   int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b, a%b);
     }

   ll solve(int curr,int mask){
        if(curr==n) return 0;
        if(dp[curr][mask]!=-1) return dp[curr][mask];

        ll r=0;
        for(int i=0;i<n;i++){
            if(!(mask & 1<<i)){    
                 r = max(r, gcd(a[curr],a[i])+solve(i, mask|(1<<i)));
             }
         }
        return (dp[curr][mask]=r);
     }


int main(){

     cin>>n;

     for(int i=0;i<n;i++){
          cin >> a[i];
       }

     memset(dp, -1, sizeof(dp));

     ll res=0;

     for(int i=0;i<n;i++){
        res = max(res, solve(i,1<<i));
     }

    cout << res;

    return 0;
}

     
