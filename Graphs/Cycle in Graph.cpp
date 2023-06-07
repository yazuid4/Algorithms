#include <iostream>
#include <vector>

using namespace std;

int n,m,k,x,y;
vector<int> vec[100005];
bool vis[100005];
int flag;
string s;
vector<int> cycle;

     bool dfs(int i, int p){

              vis[i]=true;

              for(int j=0;j<vec[i].size();j++){

                   if(vis[vec[i][j]]){
                         if(vec[i][j]!=p){

                               int m;
                               for(int q=0;q<cycle.size();q++){
                                     if(cycle[q]==vec[i][j]){
                                        m = q;break;
                                      }
                                   }

                               if(cycle.size() - m > k){
                                     cycle.push_back(vec[i][j]);
                                     return true;
                                   }
                              }
                    }else{
                           cycle.push_back(vec[i][j]);

                           if(dfs(vec[i][j], i)){
                               return true;
                             }
                         }
                    }
               return false;
           }


int main()
{
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        cin>>x>>y;
        vec[y].push_back(x);
        vec[x].push_back(y);
     }


     for(int i=1;i<=n;i++){
           if(!vis[i]){
              cycle.push_back(i);
              if(dfs(i,0)){
                   flag=1;break;
                  }
              }
          }

     //Preprocessing before printing
     int e,idx=0;
     e = cycle[cycle.size()-1];

     idx=0;
     while(cycle[idx]!=e){
          idx++;
        }

     cycle.erase(cycle.begin(), cycle.begin()+idx+1);

     //Result
     if(flag==1){

          int n = cycle.size();
          cout << n << endl;

          for(int i : cycle){
              cout <<i<<" ";
            }
     }else{
          cout << "No cycle";
     }

    return 0;
}
