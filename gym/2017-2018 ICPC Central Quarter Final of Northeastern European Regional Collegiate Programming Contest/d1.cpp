#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 1000005*4
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;
vector <int> tag(MAXN);
vector <int> arr(MAXN);
vector <int> tree(MAXN);

void build(int i,int l,int r){ 
    if(l == r){
        tree[i] = arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(cl(i),l,mid); 
    build(cr(i),mid+1,r);
    tree[i] = __gcd(tree[cl(i)], tree[cr(i)]);
}
int query(int i,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){ 
        return tree[i];
    }
    int mid=(l+r)/2, ret=0;
    if(ql<=mid)
        ret += query(cl(i),l,mid,ql,qr);
    if(qr> mid)
        ret += query(cr(i),mid+1,r,ql,qr);
    return ret;
}

void update(int i,int l,int r,int pos,int val){
    if(l == r){
        tree[i] = val;
        return;
    }
    int mid=(l+r)/2;
    if(pos <= mid) 
        update(cl(i),l,mid,pos,val);
    else 
        update(cr(i),mid+1,r,pos,val);
    tree[i] = __gcd(tree[cl(i)], tree[cr(i)]);
}

signed main(){
    io
    int n,i;
    char op;
    deque<int> dq;
    cin >> n;
    int flag = 0;
    build(1,1,n);
    for(i=0;i<n;i++){
        int temp;
        cin >> op;
        if(op=='+'){
            cin >> temp;
           update(1,1,n,i,temp); 
        }else if(op=='-'){
            update(1,1,n,i,1);
        }else{
            cout << query(1,1,n,1,n);
        }
    }
}