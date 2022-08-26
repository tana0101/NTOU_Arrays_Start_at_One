#include<bits/stdc++.h>
#define ll long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

ll pw(ll x,ll y){
    ll ans =1;
    while(y){
        if(y&1)ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}

signed main(){
    io
    ll t,n,m;
    cin >> t;
    vector<ll> a(61);
    for(int i=1;i<=60;i++){
        a[i]=pw(2,i)-1;
        //cerr<"i = "<<i <<" => "<<a[i]<<"\n";
    }
    while(t--){
        cin >> m >> n;
        if(m==1){
            if(n==1)cout<<"2\n";
            else cout<<"1\n";
        }else{
            if(n==0)cout<<a[m]+1<<"\n";
            else cout<<a[m]<<"\n";
        }
    }
}