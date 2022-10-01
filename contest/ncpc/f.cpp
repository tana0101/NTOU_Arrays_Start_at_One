#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, ns,temp;
        cin>>s;
        int nums[10];
        memset(nums,0,sizeof(nums));
        for(int i=0;i<s.size();i++){
            nums[s[i]-'0']++;
        }
        map<string,int>mp;
        temp = s;
        //mp[s]++;
        int ans;
        int cnt=1;
        while(1){
            ns="";
            for(int i=0;i<10;i++){
                if(nums[i]>0){
                    ns+=to_string(nums[i]) + to_string(i);
                }
            }/*
            if(mp[ns]==0){
                mp[ns]++;
                cnt++;
            }else if(ns!=""&&mp[ns]>0){
                ans=cnt;
                break;
            }*/            
            mp[s]++;
            cout<<s<<"\n";
            if((mp.empty()&& s==ns) || (mp.find(ns)!=mp.end())){
                if(mp.empty()&& s==ns)ans = mp.size()+1;
                else ans = mp.size();

                break;
            }
            
            s = ns;
            memset(nums,0,sizeof(nums));
            for(int i=0;i<ns.size();i++){
                nums[ns[i]-'0']++;
            }
        }
        /*for(auto it:mp){
            cout<<it.first<<"\n";
        }*/
        cout<<ans<<"\n";
    }
}