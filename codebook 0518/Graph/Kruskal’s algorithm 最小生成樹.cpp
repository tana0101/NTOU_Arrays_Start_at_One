/*Kruskal’s algorithm 最小生成樹*/
//搭配 Disjoint Set(Union-Find)
struct Edge {
    int u, v, w;  // 點 u 連到點 v 並且邊權為 w
    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.w > rhs.w;//兩條邊比較大小用邊權比較
    }
};
priority_queue<Edge> graph();// 宣告邊型態的陣列 graph
int kruskal(int m){
    int tot = 0;
    for (int i = 0; i < m ; i++) {
        if (find(graph.top().u) != find(graph.top().v)) { // 如果兩點未聯通
            merge(graph.top().u, graph.top().v);    
               // 將兩點設成同一個集合
            tot += graph.top().w;  // 權重加進答案
        }
        graph.pop();
    }
    return tot;
}
int main() {
    int u, v, w, n, m,;
    cin >> n >> m; //node,edge
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph.push(Edge{u,v,w});
    }
    cout << kruskal(m) << "\n";
    return 0;
}
