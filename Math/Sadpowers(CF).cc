/*
Link: http://codeforces.com/contest/955/problem/C

Given Q queries of the form (L, R)
For each query you have to find the number of such x that (L ≤ x ≤ R) and there exist integer numbers a>0, p>1 such that x = power(a, p).

*/

#include<iostream>
#include<limits>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>

#define  ll long long
#define  pb push_back

using namespace std;

set<ll> s;
vector<ll> v;
const ll mx = 1e18 + 18;


  void precalc(){
         for(int i = 2; i <= 1e6; i++ ){
	    ll r = i;
            while(r < mx && (log10(r)+log10(i) < log10(mx))){
                  r = r*i;
		  ll sq = sqrt(r);
		  if(sq*sq != r) v.pb(r);
		}
	    }	
        }


	
int main(){
  
  int q;
  cin >> q;

  precalc();

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(),v.end()),v.end());


  while(q--){
      ll l, r, res;
      cin >> l >> r;

      res = (upper_bound(v.begin(), v.end(), r) - v.begin()) - (upper_bound(v.begin(), v.end(), l-1) - v.begin());
      res += (ll)sqrt(r) - (ll)sqrt(l-1);

      cout << res << endl;
    }

  
  return 0;

}
















