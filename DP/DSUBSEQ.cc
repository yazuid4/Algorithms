#include<iostream> 
#include<vector>
#include<queue>
#include<map>
#include<cstring>

using namespace std;


const int mod = 1000000007;
int dp[1000005];
int p[1000005];        


int main(){


    int t;
    cin >> t;

    while(t--){
        
        memset(dp, 0, sizeof dp);
        memset(p, 0, sizeof p);

        string s;
        cin >> s;

        int n = s.length();
        dp[0] = 1;


        for(int i = 1; i <= n; i++){
                
                dp[i] = (dp[i-1] + dp[i-1])%mod;
                
                int r = s[i-1]-'0';

                if(p[r] > 0)
                    dp[i] = (dp[i] - dp[p[r] - 1])%mod;
                  

                p[r] = i;
            }
        

        cout << (dp[n] + mod)%mod << "\n";

       }

    
    return 0;
}