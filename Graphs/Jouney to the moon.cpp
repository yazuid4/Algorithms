#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[100005];
bool vis[100005];
int b[100005];


 int dfs(int i){

        vis[i]=true;
        int res = 1;

        for(int j=0;j<vec[i].size();j++){
               if(!vis[vec[i][j]]){
                    res = res + dfs(vec[i][j]);
               }
          }
        return res;
   }


int main()
{
    int n,k,t=0,s=0;
    long res=0;
    cin >> n >> k;

    int x,y;

    while(k--){
      cin >> x >> y;
      vec[x].push_back(y);
      vec[y].push_back(x);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
               b[t]=dfs(i);
               s+=b[t];
               t++;
         }
      }

    for(int i=0;i<t-1;i++){
          s-=b[i];
          res += b[i]*s;
      }

    cout << res;

    return 0;

}


