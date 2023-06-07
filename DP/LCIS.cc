/*
 Longest Common Increasing Subsequence
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

#define ll long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second

using namespace std;


vector<int> ans;
int n, m;
int L[1007];
int a[1007];
int b[1007];
int p[1007];




int main(){


    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++)cin >> b[i];


    for(int i = 0; i < n; i++){
        int curr = 0;
        int prev = -1;

        for(int j = 0; j < m; j++){
              if(a[i] > b[j] && curr < L[j]){
                    curr = L[j];
                    prev = j;
                }              
              if(a[i] == b[j] && curr + 1 > L[j]){
                    L[j] = curr + 1;
                    p[j] = prev;
                 }
             }
        }
    
    int MX = 0, idx = -1;

    for(int i = 0; i < m; i++){
           if(L[i] > MX){
               MX = L[i];
               idx = i;
             }  
        }

    if(MX == 0){
         cout << 0;
         return 0;
       }
    

    while(idx != -1){
         ans.pb(b[idx]);
         idx = p[idx];   
        }
    

    //Result
    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
      

    


    return 0;
  }

