/*
    The extended_euclidean_algorithm is an implementation of Bezout's theoreme:
                  3(x,y)inZ  such that:  a*x + b*y = GCD(a,b), where a and b integers.
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



int main()
{
    /* Test */
    int a,b,x,y;
    cin >> a >> b;

    cout << extended_euclidean_algorithm(a,b,&x,&y) << endl;
    cout << x << " " << y;


    return 0;
}
