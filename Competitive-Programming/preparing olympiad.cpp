#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,l,r,x,cnt=0;
    cin>>n>>l>>r>>x;

    vector<int> a(n+1);
    vector<vector<int>> sets;

    for(int i=0; i<n; i++){
       cin >> a[i];
    }

    for(int i=1; i<(1<<n);i++){
        vector<int> v;
          for(int j=0;j<n;j++){
               if((i&(1<<j))>0){
                 v.push_back(a[j]);
               }
            }
        sets.push_back(v);
     }

     for(auto& s: sets){
          if(s.size()>=2){
               int ma=s[0],mi=s[0],tot=0;
               for(int i=0; i<s.size();i++){
                    tot+=s[i];
                    ma = max(ma,s[i]);
                    mi = min(mi,s[i]);
               }
               if((tot>=l)&&(tot<=r)&&((ma-mi)>=x)){
                    cnt++;
               }
          }
     }

     cout << cnt;

    return 0;
}
