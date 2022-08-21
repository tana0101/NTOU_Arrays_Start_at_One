/*DFS*/

/*n皇后*/
//k為第幾行，a[k]為第幾列，n個皇后
int a[100], n, count;
void DFS(int k) {
    if (k > n) {//當k=n+1時找到解
        count++;
        printf("第%d個解\n", count);
        for (int i = 1; i <= n; i++) {//譜面輸出
            for (int j = 1; j < a[i]; j++)printf("0");
            printf("1");
            for (int j = a[i] + 1; j <= n; j++)printf("0");
            printf("\n");
        }
    }
    else {
        for (int i = 1; i <= n; i++) {//找不到合適的列（位置）,回到上一行
            a[k] = i;  //存入皇后
            if (check(a, k))DFS(k + 1);//當前皇后的位置符合要求，則求下一個皇后(下一行)
        }
    }
}

/*騎士旅行問題*/
#define X 5 //棋盤
#define Y 5
//騎士共有8個方向
int dir[8][2]={{1,2},{2,1},{1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2,-1}};
int board[X][Y]={0},tot=0,_x,_y;

void print() {
	cout<<++tot<<"\n";
	for (int i=0;i<X;i++) {
		for (int j=0;j<Y;j++)
			cout<<setw(3)<<board[i][j];
		cout<<"\n";
	}
	return;
}

void dfs(int x,int y,int t) {
	if (t>X*Y) {
		print();
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

int main(){
	cin>>_x>>_y; //起始點
	board[_x][_y]=1;
	dfs(_x,_y,2);
}
