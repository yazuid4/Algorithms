#include <iostream>

using namespace std;

#define ll long long

int main()
{
     int n,m;
     cin >> n >>m;

     int a[m];

     for(int i=0;i<m;i++){
          cin >> a[i];
        }

     ll C[n+1][m];

     for(int i=0;i<m;i++)
          {C[0][i]=1;}


     for(int i=1;i<=n;i++){
         for(int j=0;j<m;j++){
               ll s=0;

               if(j>0){
                    s+= C[i][j-1];
                }
               if(i-a[j]>=0){
                    s+= C[i-a[j]][j];
                }

           C[i][j] = s;
         }
       }

      cout << C[n][m-1];


     return 0;
}
