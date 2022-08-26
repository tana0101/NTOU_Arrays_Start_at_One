#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        vector<string>v1,v2;
        vector<int>tone1,tone2;
        for(int i=0;i<n;i++){
            cin>>s;
            v1.push_back(s.substr(0,s.length()-1));
            tone1.push_back(s[s.length()-1]-'0');
        }
        for(int i=0;i<n;i++){
            cin>>s;
            v2.push_back(s.substr(0,s.length()-1));
            tone2.push_back(s[s.length()-1]-'0');
        }
        int flag=0;
        if((tone1.back()==3||tone1.back()==4)&&(tone2.back()==1||tone2.back()==2)){
            for(int i=0;i<n-1;i++){
                if(tone1[i]==1||tone1[i]==2){
                    if(tone2[i]==1||tone2[i]==2){
                        flag=1;
                        cout<<"NO\n";
                        break;
                    }
                }
                if(tone1[i]==3||tone1[i]==4){
                    if(tone2[i]==3||tone2[i]==4){
                        flag=1;
                        cout<<"NO\n";
                        break;
                    }
                }
            }
            if(!flag)cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

// 1 (flat), 2 (rising), 3 (falling-rising), or 4 (falling)
// flat tone, rising tone -> level tones, 
// falling-rising, falling tone -> oblique tones.
// first line last is oblique tone