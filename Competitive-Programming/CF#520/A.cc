#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;




int main(){

     int n;
     cin >> n;

     int a[n+2];

     for(int i = 1; i <= n; i++){
         cin >> a[i];
      }
     
     int ans = 0;

     a[0] = 0;
     a[n+1] = 1001;

     for(int i = 0; i < n+2; i++){
        for(int j = i+1; j < n+2; j++){
              if(a[j]-a[i] == (j-i)){
                   int t = j-i-1;
                   ans = max(ans, t);
                  } 
            }
        }
        

     

    cout << ans;


    return 0;
  }
