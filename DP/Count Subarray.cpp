/*
 Problem Link: https://www.codechef.com/node?destination=/problems/SUBINC
 Autor: Yazid
*/

#include <iostream>

using namespace std;

int main()
{
int t;cin>>t;

    while(t--){

      int n;cin>>n;
      int a[n],dp[n];
      long long r=0;

      for(int i=0;i<n;i++){
          cin>>a[i];
        }

      dp[0]=1;

      for(int i=1;i<n;i++){
           if(a[i]>=a[i-1]){
                dp[i]=dp[i-1]+1;
           }
           else{
               dp[i]=1;
           }
        }

        for(int i=0;i<n;i++){
             r+=dp[i];
          }

        cout << r << endl;

     }

    return 0;
}