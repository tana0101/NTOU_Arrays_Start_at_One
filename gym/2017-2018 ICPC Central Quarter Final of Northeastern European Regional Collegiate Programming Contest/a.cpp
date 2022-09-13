#include<bits/stdc++.h>
#define ll long long

using namespace std;

signed main(){
    ll n;
    while(cin >> n){
        ll sum=0;
        for(ll i=1;i<=n*n;i++){
            sum+=i;
        }
        //cout<<sum<<"\n";
        sum/=n;
        cout<<sum<<"\n";
    }
}