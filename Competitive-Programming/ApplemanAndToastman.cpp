#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long tot=0,res=0;
    int d=n,idx=0;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
         cin >> v[i];
         tot += v[i];
     }

     res=tot;

     sort(v.begin(),v.end());

     while(d>1){

          res += tot;
          tot -= v[idx];
          d--;
          idx++;

      }

      cout << res;


    return 0;
}
