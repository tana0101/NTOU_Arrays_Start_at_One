// n：第0種到第n種物品要放進背包內。
// w：背包耐重限制。
// c(n, w)：只有第0種到第n種物品
// 耐重限制為w，此時的背包問題答案。
// weight[n]：第n種物品的重量。
// cost[n]：第n種物品的價值。
// number[n]：第n種物品的數量。

// 0/1背包滾動
// 每種物品只會放進背包零個或一個。
const int N = 500, W = 2000000; //N個物品,耐重W
int cost[N], weight[N];
int c[W + 1];
void knapsack(int n, int w){
	c[0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = w; j - weight[i] >= 0; --j)
			c[j] = max(c[j], c[j - weight[i]] + cost[i]);
	cout << c[w];
}
// Subset Sum Problem
// Partition Problem
// Bin Packing Problem

// 無限背包
// 物品有許多種類，每一種物品都無限量供應的背包問題。
void knapsack(int n, int w){
    memset(c, 0, sizeof(c));
    for (int i=0; i<n; ++i)
        for (int j = weight[i]; j <= w; ++j)
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);

    cout << "最高的價值為" << c[w];
}

// 有限背包
// 物品有許多種類，每一種物品都是限量供應的背包問題。
int cost[N], weight[N], number[N];
// number[n]：第n種物品的數量。
void knapsack(int n, int w){
    for (int i = 0; i < n; ++i)
    {
        int num = min(number[i], w / weight[i]);
        for (int k = 1; num > 0; k *= 2)
        {
            if (k > num) k = num;
            num -= k;
            for (int j = w; j >= weight[i] * k; --j)
                c[j] = max(c[j], c[j - weight[i] * k] + cost[i] * k);
        }
    }
    cout << "最高的價值為" << c[w];
}
