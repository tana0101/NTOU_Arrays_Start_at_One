#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll unsigned long long
using namespace std;

int main(){
    io
    vector<int> arr;
    ll sum=1,two=1,cnt=1;
    arr.push_back(1);
    while(sum<=1000000000){
        sum+=(cnt*two);
        arr.push_back(sum);
        cnt++;
        two*=2;
    }
    int t,k;
    cin>>t;
    while(t--){
        cin>>k;
        auto it=lower_bound(arr.begin(),arr.end(),k) - arr.begin();
        cout<<it<<"\n";
    }
}