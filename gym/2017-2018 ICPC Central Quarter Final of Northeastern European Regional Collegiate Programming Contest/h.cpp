#include <bits/stdc++.h>
#define int long long
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace::std;

signed main(){
    io
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+5);
    //f(n)=f(n-1)+f(n-x)+f(n/7)
    int ans=0;
    for(int x=2;x<n;x++){
        fill(dp.begin(),dp.end(),0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1];
            if(i>x)dp[i]+=dp[i-x];
            if((i%7)==0)dp[i]+=dp[i/7];
            //cerr << "x=" << x << " i=" << i <<" dp=" << dp[x][i]<<"\n";
        }
        if(dp[n]==k){
            ans = x;
            break;
        }
    }
    cout<<ans<<"\n";
}