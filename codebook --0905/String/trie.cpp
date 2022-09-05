// insert O(|s|)
// query  O(|s|)
struct trie{
    trie *nxt[26];
    int cnt;    //紀錄有多少個字串以此節點結尾
    int sz;     //有多少字串的前綴包括此節點
    set<int> cnt_idx, sz_idx;
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
}   };
trie *root = new trie(); 
void insert(string& s, int idx){ 
    trie *now = root;  // 每次從根結點出發
    for(auto i:s){
        now->sz++; now->sz_idx.emplace(idx); //被誰經過
        if(now->nxt[i-'a'] == NULL){
            now->nxt[i-'a'] = new trie();
        }
        now = now->nxt[i-'a'];  //走到下一個字母
    }
    now->cnt++; now->cnt_idx.emplace(idx);//以此點結尾
    now->sz++;  now->sz_idx.emplace(idx); //被誰經過
}
//query
int query_prefix(string& s){  //查詢有多少前綴為 s
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL){
            return 0;
        }
        now = now->nxt[i-'a']; 
    }
    return now->sz;
}
int query_count(string& s){  //查詢字串 s 出現次數
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL){
            return 0;
        }
        now = now->nxt[i-'a'];
    }
    return now->cnt;
}
//str有沒有在[l,r]的前綴中
bool query_ArrPrefix(string& s,int l,int r){  
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] != NULL && now->nxt[i - 'a']->sz > 0 ){ //存在
            now = now->nxt[i-'a'];
        }else return false; //不存在，無解
    }
    // 這個s的節點，[l,r]有沒有經過
    auto L = now->sz_idx.lower_bound(l);
    if(l<=*L && *L<=r)return true;
    else return false;}
//[l,r]有沒有存在於str的前綴中
bool query_StrPrefix(string& s,int l,int r){
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] != NULL && now->nxt[i - 'a']->sz > 0 ){ //存在
            now = now->nxt[i-'a'];
        }else return false; //不存在，無解
    // [l,r]存在於str的前綴中，代表有字串以str為結尾
        auto L = now->cnt_idx.lower_bound(l);
        if(l<=*L && *L<=r)return true;
    } return false;
}