#include<bits/stdc++.h>
#define int long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define push_back emplace
using namespace std;

signed main(){
    io
    int n;
    cin >> n;
    int n0 = n>>1;
    int fac=2;
    set<int> ans;
    //ans.push_back(1);
    for(int i=1;i<=n/2;i++){
        if(n%(i*2)==0)ans.push_back(i);
    }
    for(auto x:ans){
        cout << x <<" ";
    }
    //if k*2 is one of factor of n, k is answer
}