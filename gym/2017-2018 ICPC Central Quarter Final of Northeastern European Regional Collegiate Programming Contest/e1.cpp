#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace::std;

signed main(){
    io
    int n;
    string str;
    cin>>n>>str;
    reverse(str.begin(),str.end());
    vector<char> ans(n);
    int cnt=0,xxor=0,carry=0;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='1'){
            if((cnt+carry)%2==1){
                ans[i]='0';
            }else{
                ans[i]='1';
                cnt++;
            }
        }else{
            if((cnt+carry)%2==1){
                ans[i]='1';
                cnt++;
            }else{
                ans[i]='0';
            }
        }
        carry=((cnt+carry)/2);
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<"\n";
}