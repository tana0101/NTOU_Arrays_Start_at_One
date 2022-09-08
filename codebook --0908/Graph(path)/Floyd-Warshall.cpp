/*Floyd-Warshall 全點對最短路徑*/
void floyd(){
    //將每個點對距離設為INF
    memset(dist,0x3f3f3f3f,sizeof(dist));
    //dist[u][v]為點u到點v的最短路徑
    for(int i=0;i<n;i++)  dist[i][i]=0; 
    for(int i=0;i<m;i++)  cin>>u>>v>>w,dist[u][v]=w;
    for(int i=0;i<n;i++)  //窮舉中繼點
        for(int j=0;j<n;j++) //j,k窮舉點對
            for(int k=0;k<n;k++)
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
}
