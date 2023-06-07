#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int arr[10002];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>,
                greater<pair<long long, pair<int, int>>>>  Q;

int root(int i){
   if(arr[i]==i)return i;
   return arr[i] = root(arr[i]);
 }

void union_(int x, int y){
     int rootX = root(x);
     int rootY = root(y);
     if(rootX==rootY)return;
     arr[rootX] = rootY;
}


long long kruskal(){

        long long micost=0;

        while(!Q.empty()){
            pair<long long, pair<int, int>> p = Q.top();
            Q.pop();
            if(root(p.second.first)!=root(p.second.second)){
               union_(p.second.first, p.second.second);
               micost += p.first;
            }
         }
          return micost;
      }

int main()
{
     int n,m,u,v;long long w,mincost;
     cin >> n >> m;

     for(int i=1; i<=n; i++){
          arr[i]=i;
       }

     for(int i=0; i<m; i++){
          cin >> u >> v >> w;
          pair<int,int> p;
          p = make_pair(u,v);
          pair<long long, pair<int, int>> p2;
          p2 = make_pair(w,p);
          Q.push(p2);
        }

        mincost = kruskal();
        cout << minCost;

        return 0;
}
