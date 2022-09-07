#include<bits/stdc++.h>
#define io  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MXN 200005
using namespace std;

int n;
ll ww[MXN];
vector<vector<pair<int, ll>>> edge(MXN);
void init(){
    for (int i = 1; i <= n;i++){
        edge[i].clear();
    }
}
ll dfs(int x,int f){
    ll flow = 0 ;
    for(auto it:edge[x]){
        if(it.first==f){
            flow = it.second;
            continue;
        }
        ww[x] += dfs(it.first, x);
    }
    return min(flow, ww[x]);
}
int main(){
    io
    int t;
    cin >> t;
    while(t--){
        int u, v;
        ll w;
        cin >> n;
        init();
        for (int i = 1; i <= n;i++){
            cin >> ww[i];
        }
        for (int i = 0; i < n - 1;i++){
            cin >> u >> v >> w;
            edge[u].push_back(make_pair(v, w));
            edge[v].push_back(make_pair(u, w));
        }
        dfs(1, 1);
        cout << ww[1] << "\n";
    }
} 