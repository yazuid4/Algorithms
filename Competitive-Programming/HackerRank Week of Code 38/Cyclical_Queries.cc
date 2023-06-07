#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<limits>

#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second

using namespace std;

const int MAXN = 1000004;
const LL INFI = numeric_limits<LL>::max();

vector<pair<LL, LL> > vec[MAXN];
pair<LL, pair<LL, LL> > maxd;
bool vis[MAXN];
LL d[MAXN];
int n, m;
int ptr;


       void dijkstra(int src){
                  
                  memset(vis, false, sizeof vis);
                  
                  for(LL i=1; i <= ptr; i++) d[i]=INFI;

                  d[src]=0;

                  multiset<pair<LL, LL> > myset;

                  myset.insert(mp(0, src));

                  maxd.first = 0;
                  maxd.second.first = -1;
                  maxd.second.second = -1;


                  while(!myset.empty()){

                         pair<LL,LL> p = *myset.begin();
                         myset.erase(myset.begin());

                         LL x = p.second;

                         if(!vis[x]){

                         vis[x]=true;


                         for(int j = 0; j < vec[x].size(); j++){
                               if(d[vec[x][j].first] > vec[x][j].second + d[x]){
                                             d[vec[x][j].first] = vec[x][j].second + d[x];
                                             
                                             if(d[vec[x][j].first] >= maxd.first){
                                                     if(d[vec[x][j].first] == maxd.first)
                                                          {
                                                            if( vec[x][j].first > maxd.second.first){
                                                                    maxd.first = d[vec[x][j].first];
                                                                    maxd.second.first = vec[x][j].first;
                                                                    maxd.second.second  = x;
                                                              }
                                                          }
                                                          else{
                                                              maxd.first = d[vec[x][j].first];
                                                              maxd.second.first = vec[x][j].first;
                                                              maxd.second.second  = x;
                                                          }
                                                     }
                                             
                                             myset.insert(mp(d[vec[x][j].first], vec[x][j].first));
                                            }
                                     }

                                 }
                             }
                             
                   }




int main(){
    
    
    ios::sync_with_stdio(false);cin.tie();

    cin >> n;


    for(int i = 1; i <= n; i++){
         int u,v,w;
         cin >> w;

         if(i==n){
             u = n;
             v = 1;
         }
         else{
            u = i;
            v = i+1;
         }
         
         vec[u].pb(mp(v,w));
        }



     cin >> m;
     ptr = n+1;
     vector<int> tmp;
  
     for(int i = 0; i < m; i++){
          int t;
          cin >> t;


          if(t == 1){
              LL x, w;
              cin >> x >> w;
              
              dijkstra(x);

              LL y = maxd.second.first;

              if(tmp.size() != 0){
                  vec[y].pb(mp(tmp[0],w));
                  tmp.erase(tmp.begin());
              }
              else{
                  vec[y].pb(mp(ptr,w));
                  ptr++;
               }
              
            }

          if(t == 2){
              LL x, w;
              cin >> x >> w;
            //   vec[x].pb(mp(ptr,w));
            //   ptr++;

              if(tmp.size() != 0){
                  vec[x].pb(mp(tmp[0],w));
                  tmp.erase(tmp.begin());
                }
              else{
                  vec[x].pb(mp(ptr,w));
                  ptr++;
                }
            }
          
          if(t == 3){
              LL x;
              cin >> x;

              dijkstra(x);

              LL y = maxd.second.second;
              LL to_er = maxd.second.first;
              
              vector<pair<LL, LL> >::iterator it;

              for(vector<pair<LL, LL> >::iterator it = vec[y].begin(); it != vec[y].end(); ++it) {
                          if((*it).first == to_er){
                              tmp.pb((*it).first);
                              vec[y].erase(it);
                              break;
                            }
                        }
                  }
           
           

           if(t == 4){
              LL x;
              cin >> x;
              
              dijkstra(x);

              LL mi_dist = maxd.first;
              cout << mi_dist << "\n";
            }

       
      }



    return 0;
 }

