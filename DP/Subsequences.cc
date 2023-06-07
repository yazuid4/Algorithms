/* 
   Question link: http://codeforces.com/problemset/problem/597/C
   dp + (Segment tree for sum in log(n))

   dp[curr][k] = { Number of increasing subseq ends in index curr with length k }
   Formally:  dp[curr][k] = SUM{ dp[i][k-1] / i < curr && a[i] < a[curr] }
   
*/


#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#define LL long long int
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;


const int MAXN = 100005;
int n, k;
LL a[MAXN];
LL dp[MAXN][15];
LL seg[4*MAXN];



  LL  get(int nd, int s, int e, int l, int r){
              
            if(l > r || s > r || e < l)
                 return 0;
               
            if(s >= l && e <= r)
                 return seg[nd];
                
            int mid = (s + e)/2;

            return get(2*nd, s, mid, l, r) + get(2*nd+1, mid+1, e, l, r);
          }
  



  void update(int nd, int s, int e, int v, LL val){

            if(s > e)
                return;
               
            if(s == e){
                seg[nd] += val;
                return;
               }
            
            int mid = (s + e)/2;

            if(v <= mid){
                 update(2*nd, s, mid, v, val);
               }
            else{
                 update(2*nd+1, mid+1, e, v, val);
               }
            
            seg[nd] = seg[2*nd] + seg[2*nd+1];
         
          }
    
        






int main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
          cin >> a[i];
        }
    
    for(int i = 1; i <= n; i++){
         dp[i][1] = 1;
       }
    

    for(int j = 2; j <= k+1; j++){

        memset(seg, 0, sizeof seg);

        for(int i = 1; i <= n; i++){
               if(i < j){
                   dp[i][j] = 0;
                   update(1, 1, MAXN, a[i], dp[i][j-1]);
                }
               else{
                   dp[i][j] = get(1, 1, MAXN, 1, a[i]-1);
                   update(1, 1, MAXN, a[i], dp[i][j-1]);
                }
            }
        }


   
    LL ans = 0;


    for(int i = 1; i <= n; i++){
          ans += dp[i][k+1];
        }
    


    cout << ans;
    

    return 0;
 }






