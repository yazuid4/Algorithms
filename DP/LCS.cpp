/*
   Bottom-up dynamic programming solution to find LCS: longest common subsequence of two
   strings:

   LCS(abcd,agdh)= ad,  length = 2
*/

#include <iostream>

using namespace std;

int main()
{
    int n,m;
    string s1,s2;
    cin >> s1 >> s2;

    n = s1.length();
    m = s2.length();

    int LCS[n+1][m+1];
    string RES="";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){

            if(i==0) {LCS[i][j]=i;continue;}
            if(j==0) {LCS[i][j]=j;continue;}

            if(s1[i-1]==s2[j-1]){
                 LCS[i][j] = 1 + LCS[i-1][j-1];
            }else{
                 LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    //the length
    cout << LCS[n][m];


    return 0;
}
