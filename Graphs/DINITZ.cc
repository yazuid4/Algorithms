#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<limits>

#define pii pair<int,int>
#define pil pair<int,long long>
#define LL long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;

const int maxn = 1000005;
const LL MAX_INT = numeric_limits<LL>::max();

int n, m; 
int level[maxn];
int start[maxn];

struct edge{
     int x;
     int y;
     LL f;
     LL c;
     edge() {}
     edge(int a, int b, LL cap): x(a), y(b), c(cap), f(0) {}
  };

vector<edge> d;
vector<int> v[maxn];

void addEdge(int x, int y, LL c){
        edge e1 = edge(x, y, c);
        edge e2 = edge(y, x, c);
        v[x].pb(d.size());
        d.pb(e1);
        v[y].pb(d.size());
        d.pb(e2);
      }


LL DFS(int s, LL flow, int t){


     if(s == t){
         return flow; 
       }

     for(;start[s] < v[s].size(); start[s]++){
          int idx = v[s][start[s]];
          int u = d[idx].y;
          
          if(level[u] == level[s] + 1 && d[idx].f < d[idx].c){
                flow = min(flow, d[idx].c - d[idx].f);
                LL getFlow = DFS(u, flow, t);

                if(getFlow > 0){
                    d[idx].f += getFlow;
                    d[idx^1].f -= getFlow;
                    return getFlow;
                   }
               }   
           }

    return 0;
  
  }





LL Dinic_algorithm(int s, int t){

        if(s==t)return -1;
            
        LL max_flow = 0;
               
        //while there is a path
        while(1){
            
            //BFS
            //Assign levels and check flow
            queue<int> Q;
            memset(level, -1, sizeof level);

            Q.push(s);
            level[s] = 0;

            while(!Q.empty()){

                int i = Q.front();
                Q.pop();
                
                for(int j = 0; j < v[i].size(); j++){
                        int idx = v[i][j];
                        int u = d[idx].y;
                    
                        if(level[u] < 0 && d[idx].f < d[idx].c){
                              level[u] = level[i] + 1;
                              Q.push(u);
                            }
                    }
                }

            // if sink reached
            // else break
            if(level[t] >= 0){
                
                memset(start, 0, sizeof start);

                while(LL fw = DFS(s, MAX_INT, t)){
                           max_flow += fw;
                    }
            }
            else{
                break;
            }
       
        }


        return max_flow;
    }




 
int main(){
    
    cin >> n >> m;

    //Create the residual graph
    for(int i = 0; i < m; i++){
        int x, y;
        LL c;
        cin >> x >> y >> c;
        x--; y--;
        addEdge(x, y, c);
      }
    
    
    cout << Dinic_algorithm(0, n-1);

    return 0;
  
  }

