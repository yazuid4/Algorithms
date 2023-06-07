/*
  Problem link: http://www.spoj.com/problems/EZDIJKST/
*/

#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <set>
#include <cstring>

using namespace std;

int INFI = 1000000;
vector<pair<int,int>> vec[10005];
int n;


       void dijkstra(int src,int dist){

                  bool vis[n+1]={false};
                  int d[n+1];

                  for(int i=1;i<=n;i++) d[i]=INFI;

                  d[src]=0;

                  multiset<pair<int,int>> myset;

                  myset.insert({0,src});

                  while(!myset.empty()){

                         pair<int,int> p = *myset.begin();
                         myset.erase(myset.begin());

                         int x = p.second;

                         if(!vis[x]){

                         vis[x]=true;

                         for(int j=0;j<vec[x].size();j++){
                               if(d[vec[x][j].first] > vec[x][j].second + d[x]){
                                             d[vec[x][j].first] = vec[x][j].second + d[x];
                                             myset.insert({d[vec[x][j].first], vec[x][j].first});
                                            }
                                     }

                                 }
                             }

                      //Print Result
                      if(d[dist]<INFI)
                         cout << d[dist] << endl;
                      else
                         cout << "NO" << endl;
                 }


int main()
{
    int t;cin>>t;

    while(t--){

      memset(vec, 0, sizeof(vec));

      int m,u,v,w;
      cin>>n>>m;

      for(int i=0;i<m;i++){
           cin>>u>>v>>w;
           vec[u].push_back(make_pair(v,w));
       }

      int a,b;cin>>a>>b;

      dijkstra(a,b);

    }
    return 0;
}
