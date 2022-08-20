#include<bits/stdc++.h>
#define ll long long 
#define MAXN 200005 
using namespace std;

vector <ll> bit(MAXN); //BIT數組
//前綴和查詢
ll query(ll i) { //index
    ll ret = 0;
    while(i > 0) ret += bit[i], i -= i & -i; // 1-base i-lowbit(i)
    return ret;
}

//單點增值
void modify(ll i, ll val) { //index,value
    while(i <= MAXN) bit[i] += val, i += i & -i; // i+lowbit(i)
}

int main(){

    ll i,N,K,val;
    ll sum = 0;
    vector<ll> arr, arr_K;
    cin >> N >> K;
    for(i=1;i<=N;i++){
        cin >> val;
        arr.push_back(val); //原數組
        arr_K.push_back(val*K); //K倍數組
    }
    sort(arr_K.begin(),arr_K.end());
    
    for(i=0;i<N;i++){   //arr 原始數組, arr_K K倍數組
        //查找K * arr[i]前有幾個不符
        sum += i - query(lower_bound(arr_K.begin(), arr_K.end(), K * arr[i]) - arr_K.begin() + 1);  
        modify(lower_bound(arr_K.begin(), arr_K.end(), arr[i]) - arr_K.begin() + 1, 1);
    }
    
    cout << sum << "\n";
    return 0;
}
