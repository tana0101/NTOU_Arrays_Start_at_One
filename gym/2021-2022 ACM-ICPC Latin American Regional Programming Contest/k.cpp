#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int long long
using namespace std;

signed main(){
    io
    int n;
    cin>>n;
    string s;
    vector<vector<int>>v(n,vector<int>(26,0));
    int head[26]={};
    for(int i=0;i<n;i++){
        cin>>s;
        for(char c:s){
            v[i][c-'A']=1;
        }
        head[s[0]-'A']=1;
    }
    bool flag;
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=0;j<26;j++){
            if(v[i][j]==1 && head[j]==0){
                flag=0;
                break;
            }
        }
        if(flag)break;
    }
    flag?cout<<"Y\n":cout<<"N\n";
}