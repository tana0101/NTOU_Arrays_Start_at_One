#define NO_TAG 0 //懶惰記號
vector <int> tag(MAXN);
//將區間 [l, r] 的值都加 v
void push(int i,int l,int r){
    if(tag[i] != NO_TAG){ // 判斷是否有打標記
        tree[i] += tag[i];  // 有的話就更新當前節點的值
        if(l != r){  // 如果有左右子節點把標記往下打
            tag[cl(i)] += tag[i];
            tag[cr(i)] += tag[i];
        }
        tag[i] = NO_TAG; // 更新後把標記消掉
    }    
}
void pull(int i,int l,int r){
    int mid = (l+r)/2;
    push(cl(i),l,mid); push(cr(i),mid+1,r);
    tree[i] = max(tree[cl(i)], tree[cr(i)]);
}
void update(int i,int l,int r,int ql,int qr,int v){
    push(i,l,r);
    if(ql<=l && r<=qr){
        tag[i] += v;
        return;
    }
    int mid=(l+r)/2;
    if(ql<=mid)  update(cl(i),l,mid,ql,qr,v);
    if(qr> mid)  update(cr(i),mid+1,r,ql,qr,v);
    pull(i,l,r);
}