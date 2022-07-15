#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
    freopen("consonant.in","r",stdin);    // 讀 file.in 檔
    freopen("consonant.out","w",stdout);  // 寫入 file.out 檔
    */
    string s;
    while(cin>>s){
        vector<int>cont(s.length(), 0);
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='w'||s[i]=='y'){
                cnt=0;
                continue;
            }else{
                cont[i]=++cnt;
            }
        }
        for(int i=0;i<s.length();i++){
            if(cont[i]!=0){
                if(!(cont[i]&1)){
                    s[i]-=32;
                }
            }
        }
        cout<<s<<"\n";
    }
}