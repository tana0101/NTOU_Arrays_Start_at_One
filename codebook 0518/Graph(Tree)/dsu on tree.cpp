void add(int v, int p, int x){
    cnt[ col[v] ] += x;
    // now you can insert test
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
        // run a dfs on small childs and clear them from cnt
            dfs(u, v, 0);  
        
    if(bigChild != -1)
    // bigChild marked as big and not cleared from cnt
        dfs(bigChild, v, 1), big[bigChild] = 1;  
    add(v, p, 1);
    ans[v] = sum;
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0){
        add(v, p, -1);
        // now you can init to 0
    }
}