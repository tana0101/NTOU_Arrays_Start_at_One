#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define maxn 200005
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long


using namespace std;

signed main(){
    io
    int i,n,k,t,sum=0;
    int dp[maxn],a[maxn];
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    a[n]=0;
    int pre=0;
    if(a[0]<k){
        dp[0]=1;
        pre=k-a[0];
    } 
    else{
        dp[0]=(a[0]%k==0?a[0]/k:a[0]/k+1);
        if(a[0]%k!=0){
            a[0]=a[0]%k;
        }else a[0]=0;
    }
    for(i=1;i<=n;i++){
        if(pre){
            dp[i] = dp[i-1];
            a[i-1] -= pre;
            a[i-1]*=-1;
            pre=0;
        }
        dp[i] = dp[i-1]+(a[i]%k==0?a[i]/k:a[i]/k+1);
        if(a[i]%k!=0){
            a[i]=a[i]%k;
        }else a[i]=0;
    }
    cout << dp[n] <<"\n";
}