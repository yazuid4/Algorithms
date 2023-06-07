/*
   from hackerrank codesprint 13
   Algo: Disjoint set 
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int maxn = 100005;

int root[maxn], siz[maxn];
map<string, int> p;
map<int, string> sb;
int grm[maxn][3];

bool ck(int x, int y ,int s, int f, int t){      
        if(grm[x][0] + grm[y][0] <= f && grm[x][1] + grm[y][1] <= s && grm[x][2] + grm[y][2] <= t){
                      return true; 
                   }
        return false; 
      }

int root_(int i){
     
      while(root[i] != i){
            root[i] = root[root[i]];
            i = root[i];
        }
      return root[i];
   }
    

void membersInTheLargestGroups(int n, int m, int a, int b, int f, int s, int t) {
    
    
    set<int> rt;
       
    for(int i = 1; i <= n; i++){
            string st, l;
            int v;
        
            getline(cin, st);
            vector<string> li = split_string(st);
            l = li[0];
            v = stoi(li[1]);
            p[l] = i;
            sb[i] = l;
            grm[i][v-1]++;
         }
     
     int mx_rt = 0;
      
     for(int i = 1; i <= n; i++){
           siz[i] = 1;
           root[i] = i;
       }
     
     
    
     
     while(m--){
         
         string s1, s2;
         cin >> s1 >> s2;
         
         int x, y;
         x = root_(p[s1]);
         y = root_(p[s2]);
         
         if(x == y) continue;
         
         if(siz[x] + siz[y] <= b && ck(x, y, s ,f ,t)){
                if(siz[x] < siz[y]) swap(x,y);
                root[y] = root[x];
                siz[x] += siz[y];
                
                if(siz[x] > mx_rt){
                    mx_rt = siz[x];
                 }
                  
                grm[x][0] += grm[y][0];
                grm[x][1] += grm[y][1];
                grm[x][2] += grm[y][2];      
              }
        }
    
      for(int i = 1; i <= n; i++){
           if(siz[root_(i)] == mx_rt){
                  rt.insert(root[i]);  
             }   
        }
    
    
    
      if(mx_rt < a){
          
           cout << "no groups";
        }
      else{
          vector<string> res;
          
          for(int i = 1; i <= n; i++){
                 if(rt.count(root[i])){
                       res.push_back(sb[i]);  
                   }  
            }
          
          sort(res.begin(), res.end());
          
          //print res vector
          for(int i = 0; i < res.size(); i++){
                cout << res[i] << "\n";  
              }
        }
     

}

int main()
{
    string nmabfst_temp;
    getline(cin, nmabfst_temp);

    vector<string> nmabfst = split_string(nmabfst_temp);

    int n = stoi(nmabfst[0]);

    int m = stoi(nmabfst[1]);

    int a = stoi(nmabfst[2]);

    int b = stoi(nmabfst[3]);

    int f = stoi(nmabfst[4]);

    int s = stoi(nmabfst[5]);

    int t = stoi(nmabfst[6]);

    membersInTheLargestGroups(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
