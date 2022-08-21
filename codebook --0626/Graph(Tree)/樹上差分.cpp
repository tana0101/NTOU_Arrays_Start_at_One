#define MAX 3e5+5
int n;
vector<vector<int>>edge(MAX), fa(MAX, vector<int>(21, 0));
vector<int>a(MAX), dep(MAX), cnt(MAX, 0);
void dfs(int rt,int f) {
	fa[rt][0] = f;
	dep[rt] = dep[f] + 1;
	for (int i = 1; i <= 20; i++) {
		fa[rt][i] = fa[fa[rt][i - 1]][i - 1];
	}
	for (auto i : edge[rt]) {
		if (i == f)continue;
		dfs(i, rt);
	}
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) {
		swap(a, b);
	}
	for (int i = 20; i >= 0; i--) {
		if (dep[fa[a][i]] >= dep[b]) {
			a = fa[a][i];  //上跳
		}
	}
	if (a == b)
		return a;
	for (int i = 20; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}
void dfssum(int rt,int f) {
	for (auto i : edge[rt]) {
		if (i == f)continue;
		dfssum(i, rt);
		cnt[rt] += cnt[i];
	}
}
void solve() {
	int u, v, cmnlca;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 0; i < n - 1; i++) {
		cmnlca = lca(a[i], a[i + 1]);
		cnt[fa[cmnlca][0]]--;  //父節點 -v
		cnt[cmnlca]--;		   //lca -v
		cnt[a[i]]++;		   //兩端點 +v
		cnt[a[i + 1]]++;
	}
	dfssum(1, 0);
	for (int i = 1; i <= n; i++) {  //多加的減回去
		cnt[a[i]]--;
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << "\n";
	}
}
int main() {
	cin >> n;
	solve();
}