#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define int long long
#define ll  long long
#define ld  long double
#define all(x) x.begin(),x.end()
#define io  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int ans=0, upper, lower;
vector<int> a;
void merge(int l,int r){
    vector<int> suffix;
    vector<int> prefix;
    int mid=(l+r)>>1, sum=0;
    //後綴
    for(int i=mid;i>=l;i--){
        sum += a[i];
        suffix.push_back(sum);
    }
    sort(suffix.begin(),suffix.end());
    sum=0;
    //前綴
    for(int i=mid+1;i<=r;i++){
        sum += a[i];
        prefix.push_back(sum);
    }
    //二分查找
    // suf+pre<=upper -> upper-pre>=suf
    // lower<=suf+pre -> suf>=lower-pre
    for(int i=0;i<prefix.size();i++){ 
        // upper-pre >= suf >= lower-pre
        ans += upper_bound(suffix.begin(),suffix.end(),upper-prefix[i])
            -lower_bound(suffix.begin(),suffix.end(),lower-prefix[i]);
    }
}

void Divide(int front, int end) {
    if (front >= end){
        if(a[front]>=lower&&a[front]<=upper) ans++;
        return;
    }
    int mid = (front + end) >> 1;
    Divide(front, mid);
    Divide(mid + 1, end);
    merge(front, end);
}

signed main() {
    io
    ll t,n,m,i,j,k,temp,l,u;
    
    cin >> n;
    cin >> lower >> upper;
    for(i=0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
    }
    Divide(0,n-1);
    cout << ans <<"\n";

}
