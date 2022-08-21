/*Dijkstra's algorithm 單源最短路徑*/
#define MAX_V 100
#define INF 10000

struct Edge {
	int idx,w;
};
bool operator>(const Edge& a, const Edge& b) {
	return a.w > b.w;
}

int dist[MAX_V];
vector<vector<Edge> > adj(MAX_V);
void dijkstra(int vn, int s) {
	vector <bool> vis(vn, false);
	fill(dist, dist + vn, INF); dist[s] = 0;

	priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
	Edge node;
	node.idx = s; node.w = 0;
	pq.emplace(node);
	while (!pq.empty()) {
		int u = pq.top().idx; pq.pop();
		if (vis[u])continue;
		vis[u] = true;
		for (auto v : adj[u]) {
			if (dist[v.idx] > dist[u] + v.w) {
				dist[v.idx] = dist[u] + v.w;
				node.w = dist[v.idx];
				node.idx = v.idx;
				pq.emplace(node);
			}

		}
	}
}

int main() {
    int start, end, u, v, w, i, n, m;
    cin >> n >> m; //node,edge
    for(i=0;i<m;i++){
        cin >> u >> v >> w;
        Edge node;
        node.idx = v; node.w = w;
        adj[u].push_back(node);
    }
    //從start連接到end的最短路徑
    cin >> start >> end;
    dijkstra(n, start);
    if(dist[end]==INF) cout << "NO\n";
    else cout << dist[end] <<"\n";
	return 0;
}
