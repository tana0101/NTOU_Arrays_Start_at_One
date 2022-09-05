int dp[MAXN]={0};
void dfs_sz(int x,int f){
    sz[x] = 1, fa[x] = f;
    for(int i:edge[x]){
        if(i == f) continue;
        dfs1(i, x);  // 先計算完子節點的答案再算自己的
        sz[x]+=sz[i];
        dp[x]+=(dp[i]+sz[i]);
}   }
void dfs_dp(int x,int f,ll sum){
    ans += sum + dp[x]; //所有點到結點x距離總和為父節點方向距離總和 + 子樹到自己距離總和
    for(int i:edge[x]){
        if(i == f) continue;
        //tmp 為從父節點x到子節點i的距離總合為
        ll tmp = sum  //x的父節點總和 sum 到結點x的距離
                  + dp[x] - (dp[i]+sz[i]) 
                  //加上x的子樹(除了i方向)到x的距離總和
                  + (n - sz[i]); 
                  //加上從節點x到節點i的距離
        dfs2(i, x, tmp);
}   }