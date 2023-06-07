#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long MAX = 1e9;

int main()
{
    long long n,m;
    cin>>n>>m;

    vector<long long > res;
    set<long long> myset;

    long long t;
    for(long long i=0;i<n;i++){
        cin >> t;
        myset.insert(t);
     }


    for(long long i=1;i<=m;i++){
          if(!myset.count(i)){
                if(i>m){break;}
                else{
                    m = m-i;
                    res.push_back(i);
                 }
              }
            }
            

    cout <<res.size()<< endl;

    for(long long a : res){
       cout << a << " ";
      }

    return 0;
}
