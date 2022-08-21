// O(M)
// 　　　　    歐拉迴路　　　　　  歐拉路徑
// 無向圖/所有點的度數為偶數/度數為奇數的點數量不超過2
// 有向圖/所有點入度等於出度/全部點的入度出度一樣
//或剛好一個點出度-1=入度 另一點入度-1=出度，其他點入度等於出度
vector<int> path;
void dfs(int x){
    while(!edge[x].empty()){
        int u = edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}
int main(){
    build_graph();
    dfs(st); // 如果剛好一個點出度-1=入度 則為起點
    reverse(path.begin(),path.end());
}