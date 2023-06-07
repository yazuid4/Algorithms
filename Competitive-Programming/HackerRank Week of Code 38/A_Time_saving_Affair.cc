#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second

using namespace std;

const int MAXN = 100004;
const int INFI = numeric_limits<int>::max();

vector<pair<int, int> > vec[MAXN];
bool vis[MAXN];
int d[MAXN];
int n, k, m;
                  
       void dijkstra(int src,int dist){

                 
                  for(int i=1;i<=n;i++) d[i]=INFI;

                  d[src]=0;

                  multiset<pair<int,int> > myset;

                  myset.insert(mp(0, src));

                  while(!myset.empty()){

                         pair<int,int> p = *myset.begin();
                         myset.erase(myset.begin());

                         int x = p.second;

                         if(!vis[x]){

                         vis[x]=true;

                         int c = 0;
                         int ck = d[x]/k;
                         int r  = d[x]%k;

                         if(ck%2==1){
                                c = (k - r);
                              }

                         for(int j = 0; j < vec[x].size(); j++){
                               if(d[vec[x][j].first] > vec[x][j].second + d[x] + c){
                                             d[vec[x][j].first] = vec[x][j].second + d[x] + c;
                                             myset.insert(mp(d[vec[x][j].first], vec[x][j].first));
                                            }
                                     }

                                 }
                             }
                             
                 }




int main(){
    
    
    cin >> n >> k >> m;


    for(int i = 0; i < m; i++){
         int a, b, cost;
         cin >> a >> b >> cost;
         vec[a].pb(mp(b,cost));
         vec[b].pb(mp(a,cost));
     }


     dijkstra(1, n);

     cout << d[n];


    
      

    return 0;
 }

