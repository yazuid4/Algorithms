#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_numbers(int n){
             vector<int> p;
             vector<bool> a(n, true);

             for(int i=2; i*i < n; i++){
                 if(a[i]==true){
                    for(int j=i*i; j < n; j=j+i){
                         a[j]=false;
                      }
                   }
                }

            for(int i=2; i < n; i++){
                    if(a[i]==true){
                         p.push_back(i);
                    }
                 }
       return p;
   }

int main()
{
     int n;
     cin >> n;

     vector<int> p = prime_numbers(n);
     vector<int> e(p.size(),0);

     int tmp;
     for(int i=0; i < p.size(); i++){
          tmp = n;
               while( tmp%p[i]== 0 ){
                    e[i]++;
                    tmp = tmp/p[i];
                }
            }

      int k=0;
      for(int i=0; i<p.size(); i++){
          if(e[i] !=0 ){
               cout << p[i] << "-> "<<  e[i] << endl;
               k++;
           }
        }

        if(k==0){
          cout << n << "-> " << 1;
        }


    return 0;
}
