#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long

using namespace std;

vector<int> possible;
vector<vector<int>> rel;
map<int,int> cnt,poss;
int n,m,t,i,j;

void bfs(int s){
    queue<int> q;
    map<int,int>vis;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i:rel[x]){
            if(cnt[i]>=2)continue;
            if(!vis[i]){
                if(poss[i])cnt[i]++;
                q.push(i);
                vis[i]=1;
            }
        }
    }
}

signed main(){
    io
    cin>>n>>m>>t;
    while(m--){
        cin>>i>>j;
        rel[i].push_back(j);
        if(j==t){
            possible.push_back(i);
            poss[i]++;
            //cnt[i]++;
        }
            
    }
    int c=0;
    for(int i=0;i<possible.size();i++){
        bfs(possible[i]);
        if(cnt[i]==1)c++;
    }
    
}