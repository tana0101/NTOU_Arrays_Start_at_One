#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<int,int>mp;
set<int>ans;
void factor(int v){
    vector<int>ret;
    for(int i=1;i<=sqrt(v);i++){
        if(v%i==0){
            mp[i]++;
            mp[v/i]++;
        }
    }
}
void get(int w,int l){
    factor(w),factor(l);
    for(auto i:mp){
        if(i.second>1)
            ans.emplace(i.first);
    }
    mp.clear();
}
int main(){ 
    io
    int t;
    cin>>t;
    while(t--){
        int w,l;
        vector<int>w1,l1;
        cin>>w>>l;
        //cout << "test: w=" << w <<" l=" <<l <<"\n";
        get(w-1,l-1);
        get(w-2,l);
        get(w,l-2);
        cout<<ans.size();
        for(auto i:ans){
            cout<<" "<<i;
        }
        cout<<"\n";
        ans.clear();
    }
    return 0;
}