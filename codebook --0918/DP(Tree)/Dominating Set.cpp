void Dominating_Set(int u,int p){
  dp[u][2]=0;
  dp[u][0]=1;
  bool s=false;
  int sum=0,inc=INF;
  int k;
  for(k=head[u];k!=-1;k=edge[k].next){
    int to=edge[k].to;
    if(to==p)continue;
    DP(to,u);
    dp[u][0]+=min(dp[to][0],min(dp[u][1],dp[u][2]));
    if(dp[to][0]<=dp[to][1]){
      sum+=dp[to][0];
      s=true;
    }
    else{
      sum+=dp[to][1];
      inc=min(inc,dp[to][0]-dp[to][1]);
    }
    if(dp[to][1]!=INF&&dp[u][2]!=INF)dp[u][2]+=dp[to][1];
    else dp[u][2]=INF;
  }
  if(inc==INF&&!s)dp[u][1]=INF;
  else{
    dp[u][1]=sum;
    if(!s)dp[u][1]+=inc;
	}
}