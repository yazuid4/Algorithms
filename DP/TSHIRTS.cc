/*
   Little Elephant and T-Shirts:
   Codechef: https://www.codechef.com/AUG14/problems/TSHIRTS
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

const int md = 1e9+7;
vector<int> v[101];
int dp[1<<10][101];
int n;


        int solve(int mask,int curr){
               
               if(mask==((1<<n)-1)) return 1;
               if(curr>100) return 0;

               if(dp[mask][curr]!=-1) return dp[mask][curr];

               int res=0;
               //two cases: we use the i'th t-shirt or not
               //case 1:
               res = (res + solve(mask, curr+1))%md;

               //case 2:
               for(int i=0;i<v[curr].size();i++){
                      if(!(mask&(1<<v[curr][i]))){
                           res = (res + solve(mask|(1<<v[curr][i]), curr+1))%md;
                         }
                   }

               return (dp[mask][curr]=res);
            }

               
    
int main(){
   
   
   string k;int t;
   getline(cin,k);
   stringstream g(k);
   g>>t;

   while(t--){

       string tt; getline(cin, tt);
       stringstream gg(tt);gg>>n;

       memset(v, 0, sizeof(v));

       for(int i=0;i<n;i++){
            
            string line;
            getline(cin,line);
            stringstream ss(line);

            int x;string u;
            //while tokens exists
            while(ss>>u){
               stringstream s;
               s << u;
               s >> x;
               v[x].push_back(i);
              } 
   
         }

         memset(dp,-1,sizeof(dp));
         cout << solve(0,1) << endl;
      }



    return 0;
}