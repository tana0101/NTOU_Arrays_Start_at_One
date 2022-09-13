#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace::std;

signed main(){
    io
    int n,i;
    char op;
    deque<int> dq;
    cin >> n;
    int flag = 0;
    for(i=0;i<n;i++){
        int temp;
        cin >> op;
        if(op=='+'){
            cin >> temp;
            dq.push_back(temp);
            if(temp==1)flag++;
        }else if(op=='-'){
            if(dq.front()==1)flag--;
            dq.pop_front();
        }else{
            int gd = dq[0];
            for(auto j:dq){
                gd = __gcd(gd,j);
            }
            if(dq.size()==1){
                cout << "Y" << dq[0] <<"\n";
            }
            else if(dq.size()>1 && gd==1 && flag==0){
                cout << "N\n";
            }else cout << "Y"<< gd <<"\n";
        }
    }
}