#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MXN 100000
using namespace std;
ll sum=0;
vector<ll> ans[MXN];
ll di(ll n){
    ll temp = sqrt(n);
    
    if(di(temp+1) + di(temp)==n){
        
    }else if(di(temp)+di(temp)==n){

    }

}
/*
12
sqrt(12)=3;
(3)*(3+1)=12;
      |
      v
  sqet(4)=2;
(3)*(2+2)=12;
*/

signed main(){
    io
    //freopen("equal.in","r",stdin);    // 讀 file.in 檔
    //freopen("equal.out","w",stdout);  // 寫入 file.out 檔
    ll n;
    cin >> n;
    di(n);
}
