#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    while(cin>>t&&t){
        cin>>n;
        vector<vector<int>>dp(n+1,vector<int>(t+1,0)),traceback(n+1,vector<int>(t+1,0));
        vector<int>cost(n+1);
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=t;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=cost[i]&&dp[i][j]<=dp[i-1][j-cost[i]]+cost[i]){
                    dp[i][j]=dp[i-1][j-cost[i]]+cost[i];
                }
            }
        }
        int r=n,c=t;
        vector<int>pick;
    }
}