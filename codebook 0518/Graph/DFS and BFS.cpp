//DFS
void dfs(int x){
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i])
            dfs(i);
    }
}
//BFS
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i:ADJ[x]){
            if(!vis[i])
                q.push(i),vis[i]=1;
        }
    }
}
void init(int N){
    for(int i=0;i<N;i++){
        if(!adj[i].empty()) adj[i].clear();
    }
}