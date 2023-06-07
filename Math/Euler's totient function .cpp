#include <iostream>

using namespace std;

const int MX = 1000007;

int phi[MX];
int p[MX];

/*
   phi[i] is the Euler's totient function for i(sieve algorithm)

   Application:
   ------------
   then we compute The Pillai's arithmetical function:
              sum(k:1->x, gcd(k,x)) == sum(x%d==0, phi(x/d))
*/

        sieve_calc_phi(int n){

              for(int i=2;i<=n;i++){

                 if(phi[i]==i){

                    //is prime: modify phi
                    phi[i]=i-1;

                    for(int j=2*i;j<=n;j=j+i){
                          phi[j] = (phi[j]*(i-1))/i;
                        }
                    }
                }
          }


        calc_pillai(int n){

             for(int i=1;i<=n;i++){
                  for(int j=i;j<=n;j+=i){
                         p[j] += i*phi[j/i];
                   }
                }
            }


int main()
{
    int n;cin >> n;

    //initialize phi[]
    for(int i=1;i<=n;i++){
          phi[i] = i;
     }

    sieve_calc_phi(n);

    calc_pillai(n);

    for(int i=1;i<=n;i++){
       cout << p[i] << endl;
     }


    return 0;
}
