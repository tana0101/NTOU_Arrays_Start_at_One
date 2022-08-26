#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

string ans;
int sum, flag=0, nums[10];
int main(){
    io
    int t;
    cin>>t;
    while(t--){
        sum=0,ans="",flag=0;
        int first_not_zero,last;
        for(int i=0;i<10;i++){
            cin>>nums[i];
            sum+=nums[i];
        }
        for(int i=0;i<10;i++){
            if(i!=0&&nums[i]){
                first_not_zero=i;
                break;
            }
        }
        ans+=to_string(first_not_zero);
        nums[first_not_zero]--;
        int now=first_not_zero;
        for(int i=0;i<10;){
            if(nums[i]&&i!=now){
                ans+=to_string(i);
                nums[i]--;
                now=i;
                i=0;
            }else{
                i++;
            }
        }
        for(int i=9;i>=0;i--){
            while(nums[i]){
                for(int j=ans.size()-1;j>=0;j--){
                    if(){
                        
                    }
                }
                nums[i]--;
            }    
        }
        if(ans.length()==sum)cout<<ans<<"\n";
        else cout<<"-1\n";
        //cout<<ans<<"\n";
    }
}
