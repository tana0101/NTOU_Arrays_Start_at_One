#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 2147483648
using namespace std;
int main(){
    io
    int n,k,xm,xz,a,b,c;
    cin>>n>>k;
    cin>>xm>>xz>>a>>b>>c;
    int roll[3]={};
    roll[0]=xm,roll[1]=xz;
    multiset<int> ans;
    int sz=0,mini=-1;
    for(int i=1;i<=n;i++){
        roll[2]=((roll[0] * a % MOD + roll[1] * b % MOD) % MOD + c) % MOD;
        //roll[2]=xi;
        ans.insert(roll[2]);
        roll[0]=roll[1],roll[1]=roll[2];
    }
    int cnt=0;
    for(auto out=ans.rbegin();out!=ans.rend();out++){
        if(cnt==k)break;
        cout << *out <<" ";
        cnt++;
    }

}