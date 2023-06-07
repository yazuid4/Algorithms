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




int main(){
    
    int n, k;
    cin >> n >> k;

    vector<int> a;

    for(int i = 0; i < n; i++){
          int x; cin >> x;
          a.pb(x);
          
     }

    
    map<int, int> p;
    int ans = 0;
    int MX = 0;
    int a0;

    for(int i = 0; i < n; i++){
            
            int d = a[i] - i*k;
            if(!p[d])p[d] = 1;
            else p[d]++;

            if(p[d] > MX){
                MX = p[d];
                a0 = d;
              }
       } 

    for(int i = 0; i < n; i++){
          if(a[i] != (a0 + i*k)){
                ans++;
             } 
    }

    
    cout << ans;




    


    return 0;
 }

