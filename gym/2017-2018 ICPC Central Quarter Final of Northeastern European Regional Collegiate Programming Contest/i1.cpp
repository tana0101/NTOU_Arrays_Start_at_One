#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int>fac;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i==n/i){
                if(n%(i*2)==0)fac.push_back(i);
            }else{
                if(n%(i*2)==0)fac.push_back(i);
                if(n%((n/i)*2)==0)fac.push_back(n/i);
            }
        }
    }
    sort(fac.begin(),fac.end());
    auto pos = lower_bound(fac.begin(),fac.end(),n/2) - fac.begin();
    cout<<pos+1<<"\n";
    for(int i=0;i<=pos;i++){
        if(i!=0)cout<<" ";
        cout<<fac[i];
    }
    cout<<"\n";
}