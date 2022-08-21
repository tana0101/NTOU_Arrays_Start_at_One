#define MAX_V 100

struct Edge {
	int idx, w;
};
bool operator>(const Edge& lhs, const Edge& rhs) {
	return lhs.w > rhs.w;    //兩條邊比較大小用邊權比較
}

vector<vector<Edge> > adj(MAX_V, vector<Edge>(MAX_V));
priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
int prim_pq(int vn, int start) {
	int tot = 0;
	vector<bool> vis(vn, false);
	vis[start] = true;

	for (auto v : adj[start]) pq.emplace(v);
	int times = 1;
	while (!pq.empty()) {
		Edge mn = pq.top(); pq.pop();
		if (vis[mn.idx])continue;
		vis[mn.idx] = true;
		tot += mn.w;

		int u;
		for (int i = 0;; i++) {
			if (adj[mn.idx][i].w == mn.w) {
				u = adj[mn.idx][i].idx;
				break;
			}
		}
		printf("%d: <%d,%d>\n",times++, u, mn.idx);

		for (auto v : adj[mn.idx]) pq.emplace(v);
	}
	return tot;
}

int main() {
	int start, u, v, w, i, j, ans, index, min, temp;
	//input
	cin >> start;
	int count = 0;
	Edge node;
	while (cin >> u >> v >> w) {
		node.idx = v; node.w = w;
		adj[u].push_back(node);
		node.idx = u; node.w = w;
		adj[v].push_back(node);
		count++;
	}

	ans = prim_pq(count, start);
	cout << "\nThe cost of minimum spanning tree: " << ans << "\n";

	return 0;
}
