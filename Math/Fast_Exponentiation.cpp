#include <iostream>

#define ll long long

using namespace std;

    /*Recursive method*/
    Fast_Exponentiation(int x, int n){
           if(n==0) return 1;

           if(n%2==0){
                return Fast_Exponentiation(x*x,n/2);
           }else{
                return x * Fast_Exponentiation(x*x,(n-1)/2);
           }
      }

    /*Ieterative method*/
    Fast_Exponentiation_iterative(int x, int n){

           int result = 1;

           while(n!=0){

                 if(n%2==1) result *= x;

                 n = n / 2;
                 x = x*x;
            }

           return result;
        }


     /*Modular Exponentiation*/
     Fast_Exponentiation_Modular(int x, int n, int mod){

             int r = 1;

             while(n!=0){
                   if(n%2==1) r=(r*x)%mod;

                   x = (x*x)%mod;
                   n = n / 2;
               }

            return r;
         }




int main()
{
     int x,n;cin>>x>>n;
     long long mod = 1e7 + 7;

     cout << Fast_Exponentiation_Modular(x,n,mod);


    return 0;
}
