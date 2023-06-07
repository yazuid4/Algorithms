/*
    Question from spoj: http://www.spoj.com/problems/BITMAP/
    (Algorithm : BFS on white pixels)
*/

#include<iostream> 
#include<vector>
#include<queue>
#include<utility>
#include<cstring>


using namespace std;

#define f first
#define s second



const int MAXN = 500000;

int n, m;
queue< pair<int,int> > Q;
int mat[190][190];
int ans[190][190];
bool vis[190][190];



 bool isValid(int i, int j){
         if( i < 0 || i >= n  || j < 0  || j >= m ) return false;
         else return true;
       }
  
  int row[] = {0, -1, 0, 1};
  int col[] = {-1, 0, 1, 0};



      void BFS(){

            while(!Q.empty()){          
                      pair<int, int> p;
                      p = Q.front();
                      Q.pop();

                      int xc, yc;
                      xc = p.f;
                      yc = p.s;

                      for(int i = 0; i < 4; i++){
                              int nxc, nyc;
                              nxc = xc + row[i];
                              nyc = yc + col[i];

                              if(isValid(nxc,nyc) && mat[nxc][nyc] != 1){

                                  if(!vis[nxc][nyc]){
                                       vis[nxc][nyc] = true;
                                       ans[nxc][nyc] = ans[xc][yc] + 1;
                                       Q.push(make_pair(nxc,nyc));
                                   }
                                  if(vis[nxc][nyc] && ans[nxc][nyc] > ans[xc][yc] + 1){
                                              ans[nxc][nyc] = ans[xc][yc] + 1;
                                              //Q.push(make_pair(nxc,nyc));
                                            }
                                      }         
                                }

                    }
                }
           


int main(){

    int t;
    cin >> t;

    while(t--){
       
       cin >> n >> m;

       memset(vis, 0, sizeof vis);
       memset(ans, MAXN, sizeof ans);

       
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
                    char c; cin >> c;
                    mat[i][j] = c - '0';
                    
                    if(mat[i][j] == 1){
                          ans[i][j] = 0;
                          Q.push(make_pair(i,j));
                        }
                     }
                }

        

        BFS();

        
      
        for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
                  cout << ans[i][j];

                  if(j == m-1){
                      cout << '\n';
                   }
                  else{
                      cout << " ";
                  }
               }
            
          }
        
        

       }

    
    return 0;
}