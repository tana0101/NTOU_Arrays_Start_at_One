#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
    io
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    vector<ll>pref(n + 1, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + (a[i-1]-b[i-1])*(a[i-1]-b[i-1]);
    }
    int m,l,r;
    cin>>m;
    while(m--){
        cin>>l>>r;
        long double ans = sqrt(pref[r]-pref[l-1]);
        cout << fixed << setprecision(10) << ans << "\n";
    }
}