#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int unsigned long long
using namespace std;

signed main(){
    io
    int n,q,i,j,temp,op;
    vector<int> bit_zero(30,0);
    cin >> n >> q;
    for(i=1;i<=n;i++){
        cin >> temp;
        bitset<30> bit(temp);
        for(j=0;j<30;j++){
            if(bit[j]==0 && bit_zero[j]<=i){
                bit_zero[j] = i;
            }
        }
    }
    for(i=1;i<=q;i++){
        cin >> op >> temp;
        if(op==1){
           string str = "000000000000000000000000000000";
           for(j=0;j<30;j++){
            if(bit_zero[j] < temp)
                str[j]='1';
           }
           reverse(str.begin(),str.end());
           bitset<30> bit(str);
           unsigned long long s = bit.to_ullong();
           cout << s <<"\n";
        }else{
            n++;
            bitset<30> bit(temp);
            for(j=0;j<30;j++){
                if(bit[j]==0 && bit_zero[j]<=n){
                    bit_zero[j] = n;
                }
            }
        }
    }
}
