#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define N 505
using namespace std;
int n,m;
vector<vector<bool>> board(N,vector<bool>(N,0));
vector<vector<bool>> visit(N,vector<bool>(N,0));
vector<pair<int,int>>ans;
struct Pt{
    ll x,y;
};
struct Line{
    Pt st,ed;
};


void dfs(int x, int y){
    ans.push_back(make_pair(x,y));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if()
        }
    }



}
signed main(){
    io
    cin >> n >> m;
}
