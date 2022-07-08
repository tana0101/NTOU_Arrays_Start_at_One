#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define ep emplace
#define N 1000000005
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
using namespace std;
// 1≤N≤10
// The i-th of which consists of an integer Mi≥1
// ij,fj,oj (1≤ij<fj≤86400; 1≤oj≤1000)
// The sum of the Mi shall not exceed 1000
struct node{
    ll i,f,o;
    node(){}
    node(ll _i,ll _f, ll _o){
        i=_i;
        f=_f;
        o=_o;
    }
};
signed main(){
    io
    int n,m,k,i,j,x,y,temp;
    ll i0,f0,o0;
    vector<node> a;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> k;
        for(j=0;j<n;j++){
            cin >> i0 >> f0 >> o0;
            a.pb({i0,f0,o0});
        }
    }
    vector<vector<ll>> dp(86405,vector<ll>(1005,0));
    for(i=0;i<=86400;i++){
        
    }
}