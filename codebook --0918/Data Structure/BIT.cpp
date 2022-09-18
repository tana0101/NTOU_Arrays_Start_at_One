/*BIT 樹狀數組(動態前綴和)*/
//BIT and Array start at 1
#define MAXN 100005 //最大區間<MAXN
vector <int> arr(MAXN); //原始陣列
vector <int> bit(MAXN); //BIT數組

//前綴和查詢
ll query(int i) { //index
    ll ret = 0;
    while(i > 0) ret += bit[i], i -= i & -i; // 1-base i-lowbit(i)
    return ret;
}

//單點增值
void modify(int i, int val) { //index,value
    while(i <= MAXN) bit[i] += val, i += i & -i; // i+lowbit(i)
}