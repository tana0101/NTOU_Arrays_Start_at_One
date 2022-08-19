#include<bits/stdc++.h>
#define MXN 300005
using namespace std;

vector<vector<int>>edge(MXN);
vector<int>sib(MXN, 1), vis(MXN, 0);
void dfs(int x){
    vis[x]=1;
    for(auto it:edge[x]){
        if(vis[it])
            continue;
        sib[it]=0;
        dfs(it);
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vis[n]=1;
    sib[n]=1;
    sib[n-1]=0;
    dfs(n-1);
    for(int i=1;i<=n;i++){
        sib[i]==1?cout<<"A":cout<<"B";
    }
    cout<<"\n";
}