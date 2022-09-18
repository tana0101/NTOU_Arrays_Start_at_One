// insert O(lgx)
// query  O(lgx)
// 處理XOR問題
// struct
struct trie{
    trie *nxt[2];  // 差別
    int cnt;    //紀錄有多少個數字以此節點結尾
    int sz;     //有多少數字的前綴包括此節點
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
    }
};
//創建新的字典樹
trie *root = new trie(); 
void insert(int x){
    trie *now = root;  // 每次從根結點出發
    for(int i=30;i>=0;i--)
        now->sz++;
        if(now->nxt[x>>i&1] == NULL){
            now->nxt[x>>i&1] = new trie();
        }
        now = now->nxt[x>>i&1];  //走到下一個字母
    }
    now->cnt++;
    now->sz++;
}
// in this set, the maximum value of bitwise XOR x
int query(int x){ 
    trie *now = root;
    int ans=0;
    for(int i=30;i>=0;i--){// 不等於為1(0xr1=1,1xr0=1)
        if (now->nxt[!(x>>i&1)] != NULL && now->nxt[!(x>>i&1)]-> sz > 0){ //下一個存在
            ans += 1<<i;
            now = now->nxt[!(x>>i&1)];
        }
        else now = now->nxt[x>>i&1];
    }
    return ans;
}