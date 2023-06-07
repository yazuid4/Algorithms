#include <iostream>
#include <vector>

using namespace std;


   long long max_contigous_sub_array(vector<int>& t){
           long long res=t[0];
           long long tmp;

           for(int i=0; i<t.size(); i++){
               tmp=t[i];
               for(int j=i+1; j<t.size(); j++){
                    tmp = tmp + t[j];
                    if(tmp > res){
                         res = tmp;
                      }
                   }

                   if(tmp>res){
                     res = tmp;
                   }

                }

               return res;
          }


int main()
{

    int t;
    cin >> t;

    while(t--){


    int n;
    cin >> n;

    vector<int> t(n);

    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    long long l=t[0];
    long long res;

    for(int j=1; j<n; j++){
          res = t[j];
          for(int i=j-1; i>=0;i--){
               if(res + t[i] >= res){
                    res = res + t[i];
                }
            }
          l = max(l,res);
       }



    long long r2 = max_contigous_sub_array(t);

    cout << r2 << " " << l << endl;


}


    return 0;
}
