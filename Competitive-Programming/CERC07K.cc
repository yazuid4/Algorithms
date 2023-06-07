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

int n, m;
char grid[105][105];
bool vis[105][105][20];


int r[4] = {-1, 0, 0, 1};
int c[4] = {0, -1, 1, 0};

bool isValid(int x, int y){
         if(x < 0 || x > n-1 || y < 0 || y > m-1){
                   return false;       
            }
         return true;
       }
 

struct step{
    int x;
    int y;
    int mask;
    int cnt;

    step() {}
    step(int a,int b,int mk,int ct): x(a),y(b),mask(mk),cnt(ct) {};
   };



int BFS(int xs, int ys){
        
        int ans = -1;
        map<char, int> clr;
        
        clr['b'] = 1;
        clr['g'] = 2;
        clr['r'] = 4;
        clr['y'] = 8;

        queue<step> Q;
   
        step init = step(xs,ys,0,0);
        Q.push(init);

        while(!Q.empty()){

             step p = Q.front();
             Q.pop();

             if(grid[p.x][p.y] == 'X'){
                   ans = p.cnt;
                   break;
                }
            
            if(grid[p.x][p.y] == 'b' || grid[p.x][p.y] == 'g' || grid[p.x][p.y] == 'r' || grid[p.x][p.y] == 'y'){   
                           p.mask = p.mask | clr[grid[p.x][p.y]];
                       }
            
            if(vis[p.x][p.y][p.mask]){
                continue;
             }
            
            if(grid[p.x][p.y] == 'B' || grid[p.x][p.y] == 'G' || grid[p.x][p.y] == 'R' || grid[p.x][p.y] == 'Y'){  
                           
                           char cur = tolower(grid[p.x][p.y]);
                           
                           if(!(p.mask&clr[cur])){
                                continue;
                             }
                       }

            
            vis[p.x][p.y][p.mask] = 1;

            
            for(int i = 0; i < 4; i++){

                  int xn, yn;
                  xn = p.x + r[i];
                  yn = p.y + c[i];

                  if(isValid(xn, yn) && grid[xn][yn] != '#'){
                        Q.push(step(xn, yn, p.mask, p.cnt+1));
                   }
                
                }

               
            }

  
        return ans;    
           
    }





int main(){


    while(1){

        cin >> n >> m;

        if(n == 0 && m == 0) break;
       
        memset(vis, 0, sizeof vis);
        int xs, ys;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 cin >> grid[i][j];
                
                 if(grid[i][j] == '*'){
                       xs = i;
                       ys = j;
                   }
              }
           }
        
        
        int ans = BFS(xs,ys);

        if(ans == -1){
            cout << "The poor student is trapped!" << "\n";
        }
        else{
           cout << "Escape possible in "<< ans << " steps." << "\n";
        }
    }


    
    return 0;
  }

