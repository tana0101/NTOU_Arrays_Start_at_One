    n=str.size(); m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // LCS
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(str[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    // DP回溯
    string ans="";
    i=n; j=m;
    while(i>0 && j>0){
        if(str[i-1]==str2[j-1]){
            ans = str[i-1] + ans;
            i--; j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
    cout << dp[n][m] <<"\n";
    cout << ans <<"\n";