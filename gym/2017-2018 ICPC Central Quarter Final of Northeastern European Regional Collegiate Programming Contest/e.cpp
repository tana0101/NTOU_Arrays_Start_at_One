#include<bits/stdc++.h>
#define N 1000005
using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<int> pre(N,0);
    pre[0] = (s[s.size()-1]-'0');
    for(int i=s.size()-1,j=0;i>=0;i--,j++){
        if(j!=0)pre[j]=pre[j-1]+(s[i]-'0');
    }
    for(int i =0;i<n;i++){
        cout << pre[i] <<"\n";
    }
    string ans;
    for(int i=0;i<s.size()-1;i++){
        if(pre[i]>=2){
            if(pre[i]%2==0){
                ans[i]='0';
            }else{
                ans[i]='1';
            }
            pre[i+1]+=pre[i]/2;
        }else{
            if(pre[i]==1){
                ans[i] = '1';
            }else{
                ans[i] = '0';
            }
        }
    }
    for(int i=0;i<s.size()-1;i++){
        cout << ans[i];
    }
}