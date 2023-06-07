/*
http://codeforces.com/contest/931/problem/B
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

#define  ll long long
#define  pii pair<int,int> 
#define  pll pair<long long,long long> 
#define  mp make_pair
#define  pb push_back

using namespace std;

       

int main(){

  int n,a,b, res;
  cin >> n >> a >> b;

  a--;b--;
  

  int cnt=1;

  while(1){
      a = a/2;
      b = b/2;

      if(a==b){
          if(n==2){
              cout << "Final!";
              break;
            }
          else{
              cout << cnt;
              break;
          }
        }   

      cnt++;
      n = n/2;
  }
  
  
  

  return 0;
 }