// O(N+M)
for(int i=0;i<m;i++){
    cin >> u >> v;    //點 u 連到點 v
    adj[u].push_back(v);
    ++deg[v];
}
// can solve DAG
void bfs(int n){ // Topological Sort
    queue<int> q;
    for(int i=0;i<n;i++) 
        if(!deg[i]) q.push(i); //入度0先出
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i:adj[u]){
            --deg[i];
            deg_sum[i] += deg_sum[u];
            if(deg[i] == 0) q.push(i);
        }
    }
}