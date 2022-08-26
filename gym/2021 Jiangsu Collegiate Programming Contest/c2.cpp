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
            if(nums[i])last=i;
            sum+=nums[i];
        }
        for(int i=0;i<10;i++){
            if(i!=0&&nums[i]){
                first_not_zero=i;
                break;
            }
        }
        int i=0;
        if(nums[0]){
            for(int j=nums[first_not_zero];j>0;j--){
                ans = ans + to_string(first_not_zero);
            }
            for(int j=nums[0];j>0;j--){
                ans = ans + to_string(0);
            }
            i=first_not_zero+1;
        }
        for(;i<10;i++){
            for(int j=nums[i];j>0;j--){
                ans = ans + to_string(i);
            }
        }
        for(int i=1;i<ans.length()-1;){
            if(ans[i]==ans[i-1]&&ans[i]!=ans[i+1]){
                swap(ans[i],ans[i+1]);
                i=0;
            }else{
                i--;
            }
        }
        ans=ans.substr(0,sum-nums[last]);
        int ind=ans.length();
        for(int i=0;i<nums[last];i++){
            ans.insert(ind,to_string(last));
            ind-=2;
        }
        cout << ans <<"\n";
        /*
        if(nums[ans[ans.length()-1]]>1){
            for(int i=ans.length()-nums[ans[ans.length()-1]],int j=ans.length()-nums[ans[ans.length()-1]]-1;i<ans.length()-1;i++,j-=2){
                swap(ams[i],ans[j]);
            }
        }
        cout << ans <<"\n";
        */
    }
}

// 假設4出現4次,有3個間隔
// 4 1 4 2 4 3 4
// 其他數字出現的總和必定要大於等於4-1
// 否則為-1