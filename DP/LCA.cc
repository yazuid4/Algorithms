/*
  SPOJ: http://www.spoj.com/problems/LCA/
  Dp: Sparse-Table
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<cstring>
#include<cmath>


using namespace std;


const int MAXN = 100002;
int table[19][MAXN];
vector<int> v[MAXN];
int d[MAXN];


        void DFS(int i, int p){
                 
                 table[0][i] = p;

                 for(int j = 0; j < v[i].size(); j++){
                      if(v[i][j] != p){
                          d[v[i][j]] = d[i] + 1;
                          DFS(v[i][j], i);
                        }       
                    }
                }
         

        int getAncestor(int i, int j){
               int dpt = d[i] - j;

               for(int j = 18; j >= 0; j--){
                      int u = table[j][i];

                      if(u == -1) continue;

                      if(d[u] == dpt){
                           return u;
                         }
                      if(d[u] > dpt){
                           i = u;
                        }
                  }
                return -1;
              }
          



int main(){
    
    int t;
    cin >> t;

    for(int p = 0; p < t; p++){

      memset(d, 0, sizeof d);
      memset(table, -1, sizeof table);
      
      for(int i = 0; i < MAXN; i++){
           v[i].clear();
        }
      
      int n;
      cin >> n;

      for(int i = 1; i <= n; i++){
           int m;
           cin >> m;

           for(int j = 0; j < m; j++){
               int u;
               cin >> u;
               v[i].push_back(u);
               v[u].push_back(i);
            }
         }
       
       
       DFS(1, -1);


       for(int j = 1; j <= 18; j++){
           for(int i = 1; i <= n; i++){
                if(table[j-1][i] == -1) table[j][i] = -1;
                else table[j][i] = table[j-1][table[j-1][i]];
               }
            }


       int q;
       cin >> q;

       cout << "Case " << p+1 << ":" << '\n';

       while(q--){

           int a, b;
           cin >> a >> b;

           //get LCA
           if(d[a] > d[b]) a = getAncestor(a, d[a] - d[b]);
           if(d[a] < d[b]) b = getAncestor(b, d[b] - d[a]);

           if(a == b){
                 cout << a << '\n';
           }
           else{
                for(int i = 18; i >= 0; i--){
                      int acesA = table[i][a];
                      int acesB = table[i][b];

                      if(acesA != -1 && acesB != -1 && acesA != acesB){
                            a = acesA; b = acesB;
                        }
                   }
                cout << table[0][a] << '\n';
             }

         }
          
      }


    return 0;
}

