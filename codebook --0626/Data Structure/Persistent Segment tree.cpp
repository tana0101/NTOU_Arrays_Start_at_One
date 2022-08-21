#define push_back emplace_back
struct node{
    ll val;
    node *l, *r;
    node(){val = 0;}
};
ll n,idx=0;
vector<node *> version;
//用一個vector紀錄全部版本的根節點
node mem[MAXN*25];
node *newNode(){
    return &mem[idx++];
}
node *build(int l, int r){
    node *x = newNode();
    if(l == r) return x;
    int mid = (l+r)>>1;
    x->l = build(l, mid);
    x->r = build(mid+1, r);
    return x;
}
node *update_version(node *pre, ll l, ll r, ll pos, ll v){
    node *x = newNode(); //當前位置建立新節點
    if(l == r){
        x->val = v;
        return x;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){ //更新左邊
    //左邊節點連向新節點
        x->l = update_version(pre->l, l, mid, pos, v); 
        x->r = pre->r;   //右邊連到原本的右邊
    }
    else{ //更新右邊
    //右邊節點連向新節點
        x->l = pre->l;   //左邊連到原本的左邊
        x->r = update_version(pre->r, mid+1, r, pos, v);  
    }
    x->val = min(x->l->val, x->r->val); //<-修改
    return x;
}
ll query(node *x,int ql,int qr,int v){ //bin search
    if(ql == qr) return qr;
    int mid=(ql+qr)>>1;
    if(x->l->val<v) // 如果左子區間在詢問區間內
        return query(x->l,ql,mid,v);   
    else// 如果右子區間在詢問區間內
        return query(x->r,mid+1,qr,v);  
}
void add_version(int x,int v){ //修改位置 x 的值為 v
    version.push_back(update_version(version.back(), 0, n-1, x, v));
    //前一個版本
}
int find(int x) {
	int fa = query(version.back(), 0, n - 1, x);
	if (fa == x)return x;
	return find(fa);
}
void merge(int a, int b) {
	int fa = find(a), fb = find(b);
	if (sz[fa] < sz[fb])
		swap(fa, fb);
	sz[fa] += sz[fb];
	add_version(fb, fa);
}
signed main(){
    io
    ll q,temp,i,l,r;
    cin >> n >> q;
    version.push_back(build(0,n-1));
    for(i=1;i<=n;i++){
        cin >> temp;
        add_version(temp,i);
    }
    for(i=0;i<q;i++){
        cin >> l >> r;
        cout << query(version[r],0,n-1,l) <<"\n";
    }
}