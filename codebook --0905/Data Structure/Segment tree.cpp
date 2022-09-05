/*Segment tree 線段樹(區間問題)*/
//segment tree and Array start at 1
// [l,r] 最大區間設為[1,n]
// [ql,qr] 目標區間
// pos,val 修改位置,修改值
#define MAXN 100005*4  //tree大小為4n
#define cl(x) (x*2)    //左子節點index
#define cr(x) (x*2+1)  //右子節點index
#define NO_TAG 0 //懶惰記號
vector <int> tag(MAXN);
vector <int> arr(MAXN);
vector <int> tree(MAXN);

void build(int i,int l,int r){ //i為當前節點index，l,r為當前遞迴區間
    if(l == r){ // 遞迴到區間大小為1
        tree[i] = arr[l];
        return;
    }
    int mid=(l+r)/2; //往兩邊遞迴
    build(cl(i),l,mid); 
    build(cr(i),mid+1,r);
    tree[i] = max(tree[cl(i)], tree[cr(i)]); //<-可修改條件
    //將節點的值設成左右子節點的最大值
}

// i 為當前節點index, l, r當前區間左右界，ql, qr詢問左右界
int query(int i,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){ //若當前區間在詢問區間內，直接回傳區間最大值
        return tree[i];
    }
    int mid=(l+r)/2, ret=0; //<-可修改條件
    if(ql<=mid) // 如果左子區間在詢問區間內
        ret = max(ret, query(cl(i),l,mid,ql,qr));   //<-可修改條件
    if(qr> mid) // 如果右子區間在詢問區間內
        ret = max(ret, query(cr(i),mid+1,r,ql,qr));  //<-可修改條件
    return ret;
}


/*單點修改*/
void update(int i,int l,int r,int pos,int val){
    if(l == r){ // 修改 a[pos] 的值為 val
        tree[i] = val;
        return;
    }
    int mid=(l+r)/2;
    if(pos <= mid) // 如果修改位置在左子節點，往左遞迴
        update(cl(i),l,mid,pos,val);
    else // 否則往右遞迴
        update(cr(i),mid+1,r,pos,val);
    tree[i] = max(tree[cl(i)], tree[cr(i)]);    //<-可修改條件
}

/*區間修改*/
//將區間 [l, r] 的值都加 v
void push(int i,int l,int r){
    if(tag[i] != NO_TAG){ // 判斷是否有打標記,NO_TAG=0
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
        tag[i] += v; //將區間 [l, r] 的值都加 v
        return;
    }
    int mid=(l+r)/2;
    if(ql<=mid)  update(cl(i),l,mid,ql,qr,v);
    if(qr> mid)  update(cr(i),mid+1,r,ql,qr,v);
    pull(i,l,r);
}

/*動態開點*/
struct node{
    node *l, *r;
    int val,tag;
};
void update(node *x, int l, int r, int ql, int qr, int v){
    push(x, l, r);
    if(ql <= l &&  r <= qr){
        x->tag += v;
        return;
    }
    int mid=(l+r)>>1;
    if(ql <= mid){
        if(x->l == nullptr)//判斷是否有節點
            x->l = new node(); 
        update(x->l, l , mid, ql, qr, v);
    }
    if(qr >  mid){
        if(x->r == nullptr)//判斷是否有節點
            x->r = new node(); 
        update(x->r, mid+1, r, ql, qr, v);
    }
    pull(x, l, r);
}