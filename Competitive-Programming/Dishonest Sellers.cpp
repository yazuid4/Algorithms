#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k,mi=0;
    cin >> n >> k;
    int a[n],b[n];
    vector<pair<int,int>> vec;
    pair<int, pair<int,int>> p[n];

    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++)cin >> b[i];

    for(int i=0; i<n; i++){
        vec.push_back(make_pair(a[i],b[i]));
     }

    for(int i=0;i<n;i++){
          p[i] = make_pair(vec[i].first-vec[i].second, vec[i]);
     }

     sort(p, p+n);

     for(int i=0; i<k; i++){
          mi+=p[i].second.first;
     }
     for(int i=k;i<n; i++){
          mi+=min(p[i].second.first,p[i].second.second);
     }

     cout << mi;

    return 0;
}
