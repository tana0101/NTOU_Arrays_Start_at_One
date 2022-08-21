// O(N+M)
for(int i=0;i<m;i++){
    cin >> u >> v;    //點 u 連到點 v
    edge[u].push_back(v);
    ++deg[v];
}
for(int i=0;i<n;i++) 
    if(!deg[i]) que.push(i); //入度0先出
for(int i:edge[u]){
    --deg[i];
    if(deg[i] == 0) que.push(i);
}