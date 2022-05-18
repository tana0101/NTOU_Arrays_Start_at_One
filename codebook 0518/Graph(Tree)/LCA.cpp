// pre   O(NlgN)
// query O(lgN)
// 最近共同祖先
// 兩點間距離 / 兩點間最大邊 / 兩點間重合長度
// 時間戳記，判斷祖先關係
int ti = 0; // 當前時間
int tin[MAXN+5],tout[MAXN+5];
int dis[MAXN+5]; // 計算距離深度
int query[MAXN+5][lgN+5]; //點N的2^lgN祖先的最大邊
void dfs(int x,int f,int deep){ 
    fa[x] = f;
    tin[x] = ti++;
    dis[x] = deep;
    for(auto i:edge[x]){
        if(i.v == f){
            //query[x][0] = i.w;
            continue; //如果是父節點，已經走到底
        }
        dfs(i.v, x, deep+i.w);
    }
    tout[x] = ti++;
}
bool isAncestor(int u, int v){
    return tin[u]<=tin[v] && tout[u] >= tout[v];
}
// LCA
int n,lgn;
int anc[MAXN+5][lgN+5]; //點N的2^lgN祖先
int getLca(int u, int v){
    if(isAncestor(u, v))    return u; 
    // 如果 u 為 v 的祖先則 lca 為 u
    if(isAncestor(v, u))    return v; 
    // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=lgn;i>=0;i--){    
        // 判斷 2^lgN, 2^(lgN-1),...2^1, 2^0 倍祖先
        if(!isAncestor(anc[u][i], v)) 
        // 如果 2^i 倍祖先不是 v 的祖先
            u = anc[u][i];   // 則往上移動
    }
    return anc[u][0]; // 回傳此點的父節點即為答案
}
// 找出路徑最大邊
int max_cost(int u, int v){
    int max_cost = 0;
    if(u == v) return max_cost;
    for(int i=lgn;i>=0;i--){    
        // 判斷 2^lgN, 2^(lgN-1),...2^1, 2^0 倍祖先
        if(!isAncestor(anc[u][i], v)){ 
            // 如果 2^i 倍祖先不是 v 的祖先
            max_cost = max(max_cost,query[u][i]);
            u = anc[u][i];   // 則往上移動
        }
    }
    return max(max_cost,query[u][0]); 
} // max(max_cost(u,nodeLca), max_cost(v,nodeLca))
// 兩點距離
int dist(int u, int v){ 
    //depth[X] + depth[Y] - 2 * depth[ancestor]
    return dis[u] + dis[v]-2*dis[find(v)];
}
// init 建表
for(s=1;s<=n;s++) anc[s][0] = fa[s]; 
for(i=1;i<=lgn;i++){
    for(s=1;s<=n;s++){
        //點 s 的 2^i 倍祖先即為
        //s 的 2^(i-1) 倍祖先的 2^(i-1) 倍祖先
        anc[s][i] = anc[anc[s][i-1]][i-1];
        //建最大邊的表
        query[s][i] = max(query[s][i-1],query[anc[s][i-1]][i-1]);
    }
}