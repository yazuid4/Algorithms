#include <iostream>

using namespace std;

const int MAX =  1e5 + 2;

int dp[MAX],q;
string s;


int main()
{
    cin>>s;cin>>q;
    int l,r;
    int cnt=0;

    dp[0]=0;

    for(int i=1;i<s.length();i++){
           if(s[i-1]==s[i]){
                cnt++;
                dp[i]=cnt;
           }else{
                dp[i]=cnt;
            }
        }

    while(q--){
       cin >>l>>r;
       cout <<dp[r-1]-dp[l-1]<<endl;
     }


    return 0;
}
