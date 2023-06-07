/*
    Let x be the  modular inverse of an integer a modulo m:
    So  a*x = 1 mod (m)

    x exists if GCD(a,m) egal 1, it can be dertermined using extended euclidean algorithm
*/


#include <iostream>

using namespace std;


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
   int a,n;
   cin>>a>>n;

   cout << modInverse(a,n);

   return 0;
}
