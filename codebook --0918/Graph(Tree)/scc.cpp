#define MXN 200005
#define FZ(x) memset(x, 0, sizeof(x))
// 用於 DAG 2-SAT 
struct Scc{ // 強連通分量 0-base
  int n, nScc, vst[MXN], bln[MXN]; // 最後每個點所屬的連通分量存在bln陣列
  vector<int> E[MXN], rE[MXN], vec;
  void init(int _n){ //先初始化點的數量
    n = _n;
    for (int i=0; i<MXN; i++)
      E[i].clear(), rE[i].clear();
  }
  void addEdge(int u, int v){  // 加有向邊
    E[u].PB(v); rE[v].PB(u);
  }
  void DFS(int u){
    vst[u]=1;
    for (auto v : E[u]) if (!vst[v]) DFS(v);
    vec.PB(u);
  }
  void rDFS(int u){
    vst[u] = 1; bln[u] = nScc;
    for (auto v : rE[u]) if (!vst[v]) rDFS(v);
  }
  void solve(){  // 跑 kosaraju
    nScc = 0;
    vec.clear();
    FZ(vst);
    for (int i=0; i<n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(),vec.end());
    FZ(vst);
    for (auto v : vec)
      if (!vst[v]){
        rDFS(v); nScc++;
      }
  }
}scc;