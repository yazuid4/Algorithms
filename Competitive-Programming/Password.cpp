#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prefix_function(string s){
                 int n = s.length();
                 vector<int> f(n);
                 f[0]=0;

                 for(int i=1;i<n;i++){
                     int j = f[i-1];
                     while(j>0 && s[j]!=s[i]){
                         j = f[j-1];
                      }

                     if(s[j]==s[i]){j++;}
                     f[i]=j;
                  }

                  return f;
                }

int main()
{
    string s,r;
    cin >> s;

    vector<int> F = prefix_function(s);

    int l = F[s.length()-1];
    bool ind= false;

    if(l!=0){

         for(int i=1;i<s.length()-1;i++){
               if(F[i]==l){ind=true;}
             }

         if(!ind){
              l = F[l-1];
              if(l!=0){
                  for(int i=1;i<s.length()-1;i++){
                      if(F[i]==l){
                              ind=true;
                            }
                         }
                     }
              }
          }

    if(ind){
          cout << s.substr(0,l);
    }else{
          cout << "Just a legend";
     }


    return 0;
}
