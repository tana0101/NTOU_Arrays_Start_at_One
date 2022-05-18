/*Disjoint Set(Union-Find) 並查集*/
int f[N];    // 宣告父節點陣列 f
void init(int n) {
    for (int i = 0; i < n; i++)
        f[i] = i;
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)    f[y] = x;
}