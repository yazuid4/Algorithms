
// http://codeforces.com/contest/954/problem/D

#include<iostream>
#include<limits>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>

#define  ll long long
#define  pii pair<int,int> 
#define  pll pair<long long,long long> 
#define  mp make_pair
#define  pb push_back

using namespace std;

int n, m, st, t;
vector<int> v[1005];
int ds[1005], dt[1005];
bool vis[1005];
bool check[1005][1005];
queue<int> Q;

           
        void bfs(int s, int t[]){  
                    
                    memset(vis, false, sizeof(vis));
                    t[s] = 0;
                    vis[s] = true;
                    Q.push(s);

                    while(!Q.empty()){
                         int i = Q.front();
                         Q.pop();
                         
                         for(int j = 0; j < v[i].size(); j++){
                                if(!vis[v[i][j]]){
                                    t[v[i][j]] = t[i] + 1;
                                    vis[v[i][j]] = true;
                                    Q.push(v[i][j]);
                                }
                            }
                        }
                }
      
        


int main(){
  
  cin >> n >> m >> st >> t;


  for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      v[x].pb(y);v[y].pb(x);
      check[x][y] = 1;check[y][x] = 1;
   }

   bfs(st, ds);
   bfs(t, dt);

  
  int cnt = 0;

  for(int i = 1; i <= n; i++){
         for(int j = i+1; j <= n; j++){
               if(check[i][j]==0 && check[j][i]==0){
                      int mi = min(ds[i]+dt[j]+1, ds[j]+dt[i]+1);
                      if(mi >= dt[st]){
                            cnt++;
                      }
               }
         }
   }


   cout << cnt;


  
  return 0;

}