#include <iostream>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll D[102];
ll C[102][102];

     int extended_euclidean_algorithm(int a, int b, int *x, int *y){
           if(b==0){
                *x = 1;
                *y = 0;
                return a;
              }
             int x1, y1;
             int g = extended_euclidean_algorithm(b, a%b, &x1, &y1);
             *y = x1 - (a/b) * y1;
             *x = y1;

              return g;
         }

     int modInverse(int a, int m){
            int inverse,x,y;
            if(extended_euclidean_algorithm(a,m,&x,&y)==1){
                         if(x<0) x = x + m;
                         return x;
                       }
                 }


int main()
{
    int n,l,r,mod_inv;
    ll res=0,t=1;

    cin>>n>>l>>r;

    //Number of derangements of n elements
    D[0]=1;
    D[1]=0;

    for(int i=2;i<=n;i++){
           D[i] = ((i-1)*(D[i-2] + D[i-1]))%MOD;
        }

     //Binomial coefficiens(Pascal)
     for(int i=0;i<=n;i++){
          for(int j=0;j<=i;j++){
               if( j==i || j==0)
                  C[i][j] = 1;
               else
                  C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
             }
          }

     
     for(int i=l;i<=r;i++){
          res += (C[n][i]*D[i])%MOD;
       }

     res = res%MOD;

     for(int i=1;i<=n;i++){
          t = (t*i)%MOD;
      }

     t = t%MOD;

     mod_inv = modInverse(t,MOD);

     cout << (mod_inv * res)%MOD;


    return 0;
}
