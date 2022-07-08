#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MXN 2005
using namespace std;

int main(){
    ll n,e,k,a,b;
    cin>>n>>e>>k;
    vector<vector<int>>edge(MXN);
    for(int i=0;i<k;i++){
        cin>>a>>b;
        edge[a].push_back(b);
    }
    ll ans=1, con=e+1, mul;
    for(ll i=1;i<=n;i++){
        mul=con;
        for(ll j=0;j<edge[i].size();j++){
            if(abs(edge[i][j]-i)<=e){
                mul--;
            }
        }
        ans= ans*mul%MOD;
        con++;
    }
    cout<<ans<<"\n";
}