#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

vector<vector<int>> adj(4,vector<int>(2));
vector<int> vec(4);

void init(){
    adj[0][0]=1;
    adj[0][1]=2;

    adj[1][0]=0;
    adj[1][1]=3;

    adj[2][0]=0;
    adj[2][1]=3;

    adj[3][0]=1;
    adj[3][1]=2;
}
signed main(){
    io
    int t;
    init();
    cin>>t;
    while(t--){
        for(int i=0;i<4;i++){
            cin>>vec[i];
        }
        int ans=0;
        for(int i=0;i<4;i++){
            int cnt=0;
            for(auto x:adj[i]){
                if((vec[i]>0&&vec[x]>0)||(vec[i]<=0&&vec[x]<=0)){
                    ans+=vec[i]*vec[x];
                    cnt++;
                }
            }
            if(cnt==0)ans+=vec[i];
        }
        cout<<ans<<"\n";
    }
}