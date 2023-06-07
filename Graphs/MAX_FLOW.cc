/*
  Edmonds-Karp impelementation
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

#define ll long long
#define mp make_pair 
#define pb push_back
#define f first
#define s second


using namespace std;

const int maxn = 10000005;
int n, m; 
int graph[10][10];


int Ford_Fulkerson(int s, int t){

        
        int max_flow = 0;

        //while there is a path s->t
        while(1){

            queue<int> Q;
            int parent[n];
            int vis[n] = {0};
            int min_f = maxn;


            Q.push(s);
            vis[s] = 1;

            while(!Q.empty()){

                int i = Q.front();
                Q.pop();

                int check = 0;

                for(int j = 0; j < n; j++){
                    if(graph[i][j] > 0 && vis[j] == 0){
                           vis[j] = 1;
                           parent[j] = i;
                           Q.push(j);
                        }
                     }
                }


            if(vis[t]){

                //min_value & updates;
                int j = t;

                while(j != s){
                    int i = parent[j];
                    min_f = min(min_f, graph[i][j]);
                    j = i;
                  }
                
                j = t;

                while(j != s){
                    int i = parent[j];
                    graph[i][j] -= min_f;
                    graph[j][i] += min_f;
                    j = i;
                  }
                
                max_flow = max_flow + min_f;
            }
            else{
                break;
            }
         
          }

          return max_flow;
       
       } 



 
int main(){
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
             cin >> graph[i][j];
           }
        }
    
    cout << Ford_Fulkerson(0, n-1);

    return 0;
  }

