#include <iostream>

using namespace std;

bool isPrime(int n){
       if(n==1 || n==0)return false;
       if(n==2)return true;
       if(n%2==0)return false;

       for(int i=3;i*i<=n;i+=2){
          if(n%i==0)return false;
       }
       return true;
}

bool AlmostPrime(int n){
   int cnt=0;
   for(int i=2; i<n; i++){
        if(isPrime(i) && n%i==0){
           cnt++;
        }
      }
    if(cnt==2)return true;
       return false;
 }


int main()
{
    int n;cin>>n;
    int res=0;

    for(int i=1; i<=n; i++){
       if(AlmostPrime(i)){
          res++;
       }
    }

    cout << res;

    return 0;
}