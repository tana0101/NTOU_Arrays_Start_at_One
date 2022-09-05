struct Treap{
    int key,pri,sz;     //key,priority,size
    Treap *l, *r;       //左右子樹
    Treap(){}
    Treap(int _key){
        key = _key;
        pri = rand();   //隨機的數維持樹的平衡
        sz  = 1;
        l = r = nullptr;
    }
};
Treap *root;
int Size(Treap* x){ return x ? x->sz : 0 ; }
void pull(Treap *x){ x->sz = Size(x->l) + Size(x->r) + 1;}
Treap* merge(Treap *a,Treap *b){
    //其中一個子樹為空則回傳另一個
    if(!a || !b)    return a ? a : b; 
    if(a->pri > b->pri){//如果a的pri比較大則a比較上面
        a->r = merge(a->r,b);//將a的右子樹跟b合併
        pull(a);
        return a;
    }
    else{  //如果b的pri比較大則b比較上面
        b->l = merge(a,b->l);//將b的左子樹根a合併
        pull(b);
        return b;
    }
}
void splitByKth(Treap *x,int k,Treap*& a,Treap*& b){
    if(!x){  a = b = nullptr;  }
    else if(Size(x->l) + 1 <= k){
        a = x;
        splitByKth(x->r, k - Size(x->l) - 1, a->r, b);
        pull(a);
    }
    else{
        b = x;
        splitByKth(x->l, k, a, b->l);
        pull(b);
    }
}
void splitByKey(Treap *x,int k,Treap*& a,Treap*& b){
    if(!x){  a = b = nullptr;  }
    else if(x->key<=k){
        a = x;
        splitByKey(x->r, k, a->r, b);
        pull(a);
    }
    else{
        b = x;
        splitByKey(x->l, k, a, b->l);
        pull(b);
    }
}
void insert(int val){           //新增一個值為val的元素
    Treap *x = new Treap(val);  //設一個treap節點
    Treap *l,*r;
    splitByKey(root, val, l, r);//找到新節點要放的位置
    root = merge(merge(l,x),r); //合併到原本的treap裡
}                                 
void erase(int val){            //移除所有值為val的元素
    Treap *l,*mid,*r;
    splitByKey(root, val, l, r);//把小於等於val的丟到l
    splitByKey(l, val-1, l, mid);
    //小於val的丟到l,等於val的就會在mid裡
    root = merge(l,r);          //將除了val以外的值合併
}
int findVal(int val){ //小於等於val的size
    int size = -1;
    Treap *l, *r;
    splitByKey(root, val, l, r); //把小於等於val的丟到l
    size = Size(l);
    root = merge(l,r);
    return size;
}
void interval(Treap *&o, int l, int r) {// [l,r]區間
    Treap *a, *b, *c;
    splitByKey(o, l - 1, a, b), splitByKey(b, r, b, c);
    // operate
    o = merge(a, merge(b, c));
}
void inOrderTraverse(Treap* o, int print) {// 中序
    if (o != NULL){
        push(o);
        inOrderTraverse(o->l, print);
        // print
        if(print) cout << o->val <<"  ";
        inOrderTraverse(o->r, print);
    }
}
// Rank Tree
// Kth(k)：查找第k小的元素
// Rank(x)：x的名次，即x是第幾小的元素
int kth(Treap* o, int k){
    if(o == NULL || k > o -> sz || k <= 0)   return 0;
    int s = (o -> l == NULL ? 0 : o -> l -> sz);
    if(k == s + 1)  return o -> key;
    else if(k <= s) return kth(o -> l, k);
    else            return kth(o -> r, k - s - 1);
}
int rank(Node* o, int x){
    if(o == NULL) return 0;
    int res = 0;
    int s = (o -> l == NULL ? 0 : o -> l -> sz);
    if(x <= o -> key){
        res += rank(o -> l, x);
        res += x == o -> key;
    }
    else{
        res += s + 1;
        res += rank(o -> r, x);
    }
    return res;
}