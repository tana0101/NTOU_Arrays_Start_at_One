int dp[MAXN][2]; //此點，選或不選
void dfs(int x,int f){
    dp[x][1] = 1; // 狀態[1] 計算自己數量 +1
    for(int i:edge[x]){
        if(i == f)    continue;
        dfs(i, x);    // 先計算完子節點的答案再算自己的
        dp[x][0] += dp[i][1];
        dp[x][1] += min(dp[i][0],dp[i][1]);
}   }