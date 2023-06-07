/*
     The length of the longuest increasing subsequence:
     RESULT = MAX(l[j]=MAX(1 + l[i]))  i<j && a[i]<a[j] | j>=1, j<len(seq)
*/


#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int a[n],l[n],res=1;

    for(int i=0;i<n;i++){
       cin >> a[i];
       l[i]=1;
     }


     for(int j=1;j<n;j++){
          for(int i=0;i<j;i++){
               if(a[i]<a[j]){
                    l[j] = max(l[j],1+l[i]);
                  }
               }
             res = max(res,l[j]);
         }

     cout << res;

    return 0;
}

