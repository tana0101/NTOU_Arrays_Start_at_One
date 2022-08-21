#define MXN 10005
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
#define INF 1e9+5
int n;
int sz[MXN], fa[MXN], heavy[MXN], dep[MXN];
int root[MXN]; //鍊的根節點
int len[MXN]; //鍊長度
struct Edge {int u, v;};
struct node {int v, w;};
vector<Edge> edge;
vector<node> graph[MXN];
vector<int> tree[MXN];  // 第i個節點為根的線段樹
vector<int> val[MXN];   // 第i個節點為根的序列
// 子樹大小
void dfs_sz(int u, int f, int d){
	sz[u] = 1, fa[u] = f, dep[u] = d;
    for(auto v : graph[u]){
        if(v.v != f){
            dfs_sz(v.v, u, d+1);
            sz[u] += sz[v.v];
            if(sz[v.v] > sz[heavy[u]]) heavy[u] = v.v; //重兒子
        }
    }
}
// 樹鍊剖分
void dfs_hld(int u,int f){
    for(auto v : graph[u]){
        if(v.v != f){
            if(v.v == heavy[u])root[v.v] = root[u]; 
            //重兒子的根，重鍊的頭
            else root[v.v] = v.v; //輕兒子的根
            val[root[v.v]].push_back(v.w); //點權
            dfs_hld(v.v, u);
        }
    }
    len[root[u]]++; //鍊長度
}
// LCA
int getLca(int x,int y){
    while(root[x] != root[y]){
        if(dep[root[x]] > dep[root[y]]) 
            x = fa[root[x]]; //跳鍊
        else                            
            y = fa[root[y]];
    }
    return (dep[x] <= dep[y] ? x : y);
}
// 線段樹
void build(int ver,int i,int l,int r){
    if(l == r){
        tree[ver][i] = val[ver][l];
        return;
    }
    int mid=(l+r)>>1;
    build(ver, cl(i), l, mid);
    build(ver, cr(i), mid+1, r);
    tree[ver][i] = max(tree[ver][cl(i)], tree[ver][cr(i)]); //最大邊
}
void update(int ver,int i,int l,int r,int pos,int val){
    if(l == r){ // 修改 a[pos] 的值為 val
        tree[ver][i] = val; return;
    }
    int mid=(l+r)>>1;
    if(pos <= mid) update(ver,cl(i),l,mid,pos,val);
    else           update(ver,cr(i),mid+1,r,pos,val);
    tree[ver][i] = max(tree[ver][cl(i)], tree[ver][cr(i)]);
}
 // i 為當前節點index, l, r當前區間左右界，ql, qr詢問左右界
int query(int ver,int i,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        return tree[ver][i];
    }
    int mid=(l+r)>>1, ret=-INF;
    if(ql<=mid) ret = 
        max(ret, query(ver,cl(i),l,mid,ql,qr));
    if(qr> mid) ret = 
        max(ret, query(ver,cr(i),mid+1,r,ql,qr));
    return ret;
}
void init(){
    edge.clear(); edge.resize(n-1);
    for(int i=1;i<=n;i++){
        graph[i].clear();
        tree[i].clear();
        val[i].clear();
        heavy[i]=len[i]=0;
    }   
}
signed main(){
    int i,t,a,b,w,ti;
    string op;
    cin >> n;
    init();
    for(i=0; i+1<n; i++){
        cin >> a >> b >> w;
        graph[a].push_back(node{b,w});
        graph[b].push_back(node{a,w});
        edge[i] = Edge{a,b};
    }
    val[1].push_back(-INF);
    root[1] = 1;
    dfs_sz(1, 1, 0);
    dfs_hld(1, 1);
    // build tree
    for(i=1;i<=n;i++){ // 第i個節點為根的線段樹
        if(root[i] == i){
            tree[i].resize(len[i]*4,0);
            build(i, 1, 0, len[i]-1);
        }
    }
    // query
    while(cin >> op){
        if(op == "DONE") break;
        else if(op == "CHANGE"){
            cin >> i >> ti; i--;
            if(dep[edge[i].u] < dep[edge[i].v]) 
                swap(edge[i].u,edge[i].v);
            i = edge[i].u;
            update(root[i], 1, 0, len[root[i]]-1, 
            dep[i]-dep[root[i]], ti);
        }
        else if(op == "QUERY"){
            cin >> a >> b;
            int ans = -INF;
            while(root[a] != root[b]){ //不同鍊
                if(dep[root[a]] < dep[root[b]]) 
                    swap(a, b);
                // 深鍊的最大邊
                ans = max(ans, query(root[a], 1, 0, len[root[a]]-1, 0, dep[a]-dep[root[a]]));
                a = fa[root[a]]; //跳鍊
            }
            if(a != b){ //不同節點
                int mn = 
                    min(dep[a],dep[b])-dep[root[a]]+1;
                int mx = 
                    max(dep[a],dep[b])-dep[root[a]];
                //所在節點區間 mn,mx
                ans = max(ans, query(root[a], 1, 0, len[root[a]]-1, mn, mx));
            }
            cout << ans <<"\n";
}   }   }   