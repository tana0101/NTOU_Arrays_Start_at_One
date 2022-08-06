#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

struct customer{
    int left,right,id;
};

bool cmp(customer a,customer b){
    if(a.left==b.left)
        return a.right<b.right;
    return a.left<b.left;
}

int main() {
    io
    int n,m,tmp;
    vector<int> house,ice;
    vector<customer> scope(200005);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        house.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        ice.push_back(tmp);
    }
    sort(ice.begin(),ice.end());
    for(int i=0;i<n;i++){
        int min_dist=INT_MAX,min_ind;
        for(int j=0;j<m;j++){
            if(abs(ice[j]-(i*100))<min_dist){
                min_dist=abs(ice[j]-(i*100));
                min_ind=j;
            }
        }
        scope[i].left=(i*100)-min_dist;
        scope[i].right=(i*100)+min_dist;
        scope[i].id=i;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=house[i];
        for(int j=i+1;j<n;j++){
            if(scope[j].left<scope[i].right){
                sum+=house[j];
            }else if(scope[i].left>=scope[j].left&&scope[i].right<=scope[j].right){
                sum+=house[j];
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<"\n";
}
