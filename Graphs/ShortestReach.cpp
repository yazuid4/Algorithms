#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

vector<int> vec[1005];
bool visited[1005];
map<int, int> layer;

int d=0;

  void bfs(int s){

       queue<int> Q;
       Q.push(s);
       layer[s]=0;
       visited[s]=true;

       while(!Q.empty()){
            int k = Q.front();
            Q.pop();

            for(int i=0; i<vec[k].size(); i++){
                   if(!visited[vec[k][i]]){
                         layer[vec[k][i]]=layer[k]+1;
                         Q.push(vec[k][i]);
                         visited[vec[k][i]]=true;
                       }
                    }
                 }
        }
        
int main()
{
    int t;
    cin >> t;

    while(t--){
         //initialize variables
         memset(visited,0,sizeof(visited));
         memset(vec,0,sizeof(vec));

         int n,m,s;
         cin >> n >> m;

         for(int i=0; i<=n; i++){
           layer[i]=0;
         }

         int u,v;
         for(int i=0; i<m; i++){
             cin >> u >> v;
             vec[u].push_back(v);
             vec[v].push_back(u);
          }

          cin >> s;

          bfs(s);

          for(int i=1; i<=n; i++){
               if(i==s)continue;
               if(layer[i]==0){
                    cout << "-1 ";
               }else{
                    cout << (layer[i]*6)<<" ";
               }
            }

           cout << endl;
        }

    return 0;
}
