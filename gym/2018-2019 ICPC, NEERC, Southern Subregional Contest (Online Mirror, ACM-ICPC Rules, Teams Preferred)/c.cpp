#include<bits/stdc++.h>
#define cl(i) i<<1
#define cr(i) i<<1|1
#define MXN 2e5*4+5
#define ll long long
using namespace std;

vector<ll>tree(MXN);
vector<int>tag(MXN, 0);
void push(int i,int l,int r){
    if(tag[i]!=0){
        tree[i]+=tag[i];
        if(l!=r){
            tag[cl(i)]+=tag[i];
            tag[cr(i)]+=tag[i];
        }
        tag[i]=0;
    }
}
void pull(int i,int l,int r){
    int mid=(l+r)>>1;
    push(cl(i),l,mid);
    push(cr(i),mid+1,r);
    tree[i]=max(tree[cl(i)],tree[cr(i)]);
}
int main(){
    int n,k,m,l,r,c,p;
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        cin>>l>>r>>c>>p;
    }
}