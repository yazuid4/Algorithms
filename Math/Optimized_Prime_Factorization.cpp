#include <iostream>
#include <vector>

using namespace std;

   /*
      We start by computing least prime factor for every number from 2 till MAX = 1e7 + 7
      using the sieve: complexity O(n log(log(n)))
   */

const int MAX = 1e7 + 7;

int LPF[MAX];

    void least_prime_factor(){

              for(int i=2;i*i<MAX;i++){

                     if(LPF[i]==0){
                          //i is prime
                          LPF[i]=i;

                          for(int j=i*i;j<=MAX;j+=i){
                               if(LPF[j]==0)
                                     LPF[j]=i;
                               }
                           }
                    }
              }

     vector<int> getPrimeFactorization(int n){

                      vector<int> v;

                      while(n!=1){
                            v.push_back(LPF[n]);
                            n = n / LPF[n];
                      }
                      return v;
                 }



int main()
{
    int n;cin>>n;
    vector<int> v;

    least_prime_factor();

    v = getPrimeFactorization(n);

    for(int p : v){
         cout << p << " ";
       }

    return 0;
}
