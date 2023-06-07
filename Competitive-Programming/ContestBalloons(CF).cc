/*
  http://codeforces.com/contest/725/problem/D
*/


#include<iostream>
#include<limits>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>

#define  ll long long
#define  pii pair<int, int> 
#define  pll pair<long long, long long> 
#define  mp make_pair
#define  pb push_back 
#define  fi first
#define  se second


using namespace std;


int main(){

   int n;
   cin >> n;

   ll x, y;
   cin >> x >> y;

   vector<pll> v;
   priority_queue<ll, vector<ll>, greater<ll> > Q;

   for(int i=0; i < n-1; i++){
        ll t, w;
        cin >> t >> w;
        v.pb(mp(t, w));
     }

  sort(v.rbegin(), v.rend());
   
   int i = 0;

   for(i = 0; i < n-1 && v[i].fi > x; i++){
          Q.push(v[i].se - v[i].fi + 1);
        }

    int res = Q.size();


    while(!Q.empty()){
           
            ll k = Q.top();

            if(k > x){
                 break;
              }

            x = x - k;
            Q.pop();

            for(; i<n-1 && v[i].fi > x ; i++){
                   Q.push(v[i].se - v[i].fi + 1);
               }
           
            res = min(res, (int)Q.size());
        }

      cout << res + 1;
   

  

   return 0;

 }



