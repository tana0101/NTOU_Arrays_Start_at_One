void dfs(int x){
    vis[x]=1;
    for(int i:adj[x])
        if(!vis[i]) dfs(i);
}
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i:adj[x])
            if(!vis[i])
                q.push(i),vis[i]=1;
    }
}