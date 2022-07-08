#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define N 105
#define MXN 105
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair

using namespace std;
struct node{
    ll x,y;
};
struct Edge{
    int u,v,w;
    friend bool operator<(const Edge& l,const Edge& r){
        return l.w>r.w;
    }
};
int f[N],sz[N];
void init(int n){
    for(int i=0;i<n;i++){
        f[i]=i;
        sz[i]=1;
    }
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x), y=find(y);
    if(x!=y){
        f[y]=x;
        sz[x]+=sz[y];
    }
}
priority_queue<Edge> graph(N);
int kruskal(int m){
    int tot=0;
    for(int i=0;i<m;i++){
        if(find(graph.top().u)!=find(graph.top().v)){
            merge(graph.top().u,graph.top().v);
            tot +=graph.top().w;
        }
        graph.pop();
    }
    return tot;
}

signed main(){
    io
    int n,k,i,x,y;
    for(i=0;i<n;++){
        if(i<k){ // cap
            cin >> x >> y;
            node temp; temp.x=x; temp.y=y;

        }else{ // city
            cin >> x >> y;
            node temp; temp.x=x; temp.y=y;

        }
    }

