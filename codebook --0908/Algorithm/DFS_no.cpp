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

/*交集法*/
//index=走訪位置，ans[]=答案，m為inp的序號
void DFS(int index, int m) {

    if (m == inp_size) {//等於最後一個
        for (int j = 0; j < n; j++) {   //check有重複出現的位置。
            ans[j] = ans[j] & tmp[j]; //位元運算
        }
    }

    else {
        while (index < n) {
            if (check(index, inp[m])) {  //判斷可不可以放進去。
                for (int j = 0; j < inp[m]; j++) {  //放入方塊。
                    tmp[index + j] = 1;
                }
                DFS(index + inp[m], m + 1);    //進到下一層，左子樹。
                for (int j = 0; j < inp[m]; j++) {  //回復上一動，回節點。
                    tmp[index + j] = 0;
                }
            }
            index++;
		}
	}}