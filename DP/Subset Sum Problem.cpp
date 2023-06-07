#include <iostream>

/*
  Optimized approch to check the possibility to have a subset with the given sum m;

  Example of a test:
  4 5
  a[]: {1,8,90,4}

  Answer true : {1,4} sums to m=5
*/

using namespace std;

int main()
{

    int n,m;cin>>n>>m;

    int a[n];

    for(int i=0;i<n;i++){
       cin >> a[i];
     }

     bool S[n][m+1];

     //base cases
     for(int i=0;i<n;i++){S[i][0]=true;}
     for(int i=1;i<=m;i++){S[0][i]=false;}


     for(int i=0;i<n;i++){
          for(int j=1;j<=m;j++){
               //if the the i'th coin value bigger than sum j
               if(j<a[i]) {
                    S[i][j] = S[i-1][j];
               //Otherwise
               }else{
                    S[i][j] = S[i-1][j-a[i]] || S[i-1][j];
               }
            }
         }


     if(S[n-1][m])
           cout << "Exist a subset with sum " << m;
     else
          cout << "No a subset with the given sum";



    return 0;
}
