#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define MAXN 10005
using namespace std;

int sum[3];
signed main(){
    io
    int i,j,n,temp;
    
    cin >> n;
    vector<int> a(n+1),b(n+1);
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    for(j=1;j<=n;j++){
        cin >> b[j];
    }
    for(i=1;i<=n;i++){ // n<=10^5
        for(j=1;j<=n;j++){
            temp = (i+j)%3;
            sum[temp]+=a[i]*b[j];
        }
    }
    cout << sum[0] <<" "<< sum[1] <<" "<< sum[2] <<" ";
}