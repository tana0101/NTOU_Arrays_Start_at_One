/*n queen*/
//k為第幾行，a[k]為第幾列，n個皇后
int a[100], n, count;
void DFS(int k) {
    if (k > n) {//當k=n+1時找到解
        count++;
        print("anser");
    }
    else {
        for (int i = 1; i <= n; i++) {
            a[k] = i;  //存入皇后
            if (check(a, k))DFS(k + 1);//放入，求下一行
        }
    }
}
/*Traveling Knight Problem*/
#define X 5 //棋盤
#define Y 5
int dir[8][2] = 
{{1,2},{2,1},{1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2,-1}};
int board[X][Y]={0},tot=0,_x,_y;
void dfs(int x,int y,int t) {
	if (t>X*Y) {
		print("anser");
		return;
	}
	for (int i=0;i<8;i++) {
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if ((xx>=X)||(xx<0)||(yy>=Y)||(yy<0)||(board[xx][yy])) continue;
		board[xx][yy]=t;
		dfs(xx,yy,t+1);
		board[xx][yy]=0; //回溯
	}
}
signed main(){
	board[_x][_y]=1; //starts
	dfs(_x,_y,2);
}
