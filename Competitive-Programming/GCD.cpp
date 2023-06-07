#include <iostream>
#include <vector>

using namespace std;

const long long M = 1e9 + 7;


int gcd(int a, int b){
       if(b==0)return a;
       else return gcd(b,a%b);
   }


int main()
{
     int n;cin>>n;

     vector<int> vec(n);

     for(int i=0; i<n; i++){
          cin>>vec[i];
      }

      long long g=vec[0],f=vec[0];

      for(int i=1; i<n; i++){
           f = (f*vec[i])%M;
           g = gcd(g,vec[i]);
      }



      long long res=1;
      for(int i=0; i<g; i++){
          res = (res*f)%M;
      }

      cout << res;

    return 0;
}
