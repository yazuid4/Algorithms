#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    int cnt=1,q;

    vector<int> a(n);
    set<int> myset;

    for(int i=0;i<n;i++){
          cin>>a[i];
      }

     myset.insert(a[n-1]);
     a[n-1]=1;


    for(int i=n-2;i>=0;i--){

             if(!myset.count(a[i])){
                 cnt++;
                 myset.insert(a[i]);
                 a[i]=cnt;
               }
             else{
                  a[i]=cnt;
                }
          }


     while(m--){
          cin>>q;
          cout<<a[q-1]<<endl;
       }


    return 0;
}
