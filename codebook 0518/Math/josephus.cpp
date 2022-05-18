/*約瑟夫問題：n個人圍成一桌，數到m的人出列*/
int josephus(int n, int m) {	//n人每m次
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + m) % i;
    return ans;
}