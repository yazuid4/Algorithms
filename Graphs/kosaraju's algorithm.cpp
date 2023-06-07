/*
  The code uses double dfs to calculate (C-D) in a given directed graph
  Stack helps to do a topological sorting (by the dfs_1 finishing time of each node)
  where:
     c= Sum of number of nodes in all strongly connected components with odd number of nodes.
     d= Sum of number of nodes in all strongly connected components with even number of nodes.

  Algorithm: Kosaraju's algorithm
  Complexity: O(V+E)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

bool vis[1002];
vector<int> v[1002];
vector<int> r[1002];
stack<int> S;

   void dfs_1(int i){
         vis[i]=true;
         for(int j=0;j<v[i].size();j++){
             if(!vis[v[i][j]]){
                 dfs_1(v[i][j]);
               }
           }
         S.push(i);
       }


   int dfs_2(int i){
         vis[i]=true;
         int res=1;
         for(int j=0;j<r[i].size();j++){
             if(!vis[r[i][j]]){
                 res=1+dfs_2(r[i][j]);
                }
             }
          return res;
         }


int main()
{
    int n,m;
    cin >>n>>m;

    int x,y;
    for(int i=0;i<m;i++){
       cin>>x>>y;
       v[x].push_back(y);
       r[y].push_back(x);
     }

     for(int i=1;i<=n;i++){
        if(!vis[i]){
          dfs_1(i);
         }
      }

      for(int i=1;i<=n;i++){
          vis[i]=false;
      }

      int c=0,d=0;

      while(!S.empty()){
           int s = S.top();
           S.pop();

           if(!vis[s]){
              int cnt=  dfs_2(s);
              if(cnt%2==1){c=c+cnt;}
              else{d=d+cnt;}
           }
        }

      cout<<(c-d);

    return 0;
}
