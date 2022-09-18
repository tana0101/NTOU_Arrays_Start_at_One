int f[N];    // 宣告父節點陣列 f
int sz[N]; // 子樹大小
void init(int n) {
    for (int i = 0; i < n; i++){
        f[i] = i;
        sz[i] = 1;
    }
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y){
        sz[x] += sz[y];
        f[y] = x;
    }    
}