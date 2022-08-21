#define N 100
#define INF 1000

int dist[N][N];
vector<vector<int> > length(N,vector<int>(N));

void BellmanFord(int n, int v)
{ /* n為節點總數，計算單一起點v/所有終點的最短路徑，其中邊長允許是負值，length為adjacency matrix */
    for (int k = 0; k < n; k++)for (int i = 0; i < n; i++)i == 0 ? dist[k][i] = 0 : dist[k][i] = INF; /* 對dist做初始化 */
    for (int i = 0; i < n; i++)if(length[v][i])dist[1][i] = length[v][i]; /* 對dist[1]做初始化 */
    
    for (int i = 0; i < n; i++) {
        dist[1][i] == INF ? cout << "i" : cout << dist[1][i];
        if (i != n - 1)cout << " ";
    }cout << "\n";

    for (int k = 2; k <= n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int i = 0; i < length[u].size(); i++) {
                if (!length[u][i])continue;
                if (length[u][i] == INF)continue;
                if (dist[k][i] > dist[k-1][u] + length[u][i])
                    dist[k][i] = dist[k-1][u] + length[u][i];
            }
        }
        for (int i = 0; i < n; i++) {
            dist[k][i] == INF ? cout << "i" : cout << dist[k][i];
            if (i != n - 1)cout << " ";
        }if (k != n - 1)cout << "\n";
    }
}
int main() {
    int i, u, v, w,s,vn;
    set<int> _set;

    while (cin >> u >> v >> w) {
        length[u][v] = w;
        _set.insert(u);
        _set.insert(v);
    }

    s = 0;
    vn = _set.size();
    BellmanFord(vn,s);

    return 0;
}