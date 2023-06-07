#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bitset>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;



int main(){

     int n;
     cin >> n;
     
     if(n == 1){
          cout << n << " " << 0;
          return 0;
       }

     int mx = 1, cnt = 0, c = 0, ck = 0, p = 1;
     int t = n;
     set<int> st;

     for(int i = 2; i <= t; i++){
          if(n%i==0){
               c = 0;
               while(n%i==0){
                    n = n / i;
                    c++;
                  }
               
               st.insert(c);
               
               p *= i;
               if(c > mx) mx = c;
            } 
        }

 

     if((mx&(mx-1)) == 0){
          if(st.size() > 1) cnt++;
      }
     else{
          int b;
          for(b = 30; b >= 0; b--){
              if(mx > (1 << b)){
                   b++;break;
                }
             } 
          
          mx = (1 << b);
          cnt++;
      }
     
     int bset = 0;

     while(mx != 1){
          mx = mx / 2;
          bset++;
         }

     
     
     cnt += bset;


     cout << p << " " << cnt;
 
     
    return 0;
  }