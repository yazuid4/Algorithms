/*
 SPOJ: http://www.spoj.com/problems/CPCRC1C/
 Dynamic programming approch to compute the sum of all digits of numbers in the range [a,b]
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

#define ll long long

using namespace std;

int a, b;
ll dp[30][300][2];



    vector<int> Number_to_vector(int n){
                   
                   vector<int> v, w;
                   while(n != 0){
                       v.push_back(n%10);
                       n = n/10;
                     }
                 
                    return v;
                }
    

    ll digit_sum(int i, int t, int sum, vector<int>& v){
            
            if(i == -1){
                  return sum;
                }
            
            if(dp[i][sum][t] != -1 && t != 1){
                  return dp[i][sum][t];
                }

            ll res = 0;
            int k;

            if(t == 1) k = v[i];
            else k = 9;

            for(int j = 0; j <= k; j++){

                 int tn;
                 if(j == v[i]) tn = t;
                 else tn = 0; 

                 res += digit_sum(i-1, tn, sum + j, v);           
               }
            
            
            if(!t) dp[i][sum][t] = res;
            
            return res;
         }



int main(){

    memset(dp, -1, sizeof dp);

    while(scanf("%d%d", &a, &b)){
         
         if(a==-1 && b==-1) break;

         vector<int> va, vb;
         ll ans1, ans2;
         a--;

         va = Number_to_vector(a);
         ans1 = digit_sum(va.size()-1, 1, 0, va);
         vb = Number_to_vector(b);
         ans2 = digit_sum(vb.size()-1, 1, 0, vb);

         cout << (ans2 - ans1) << "\n";

    }
     
     

    return 0;
}