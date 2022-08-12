#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

int main() {
    io
    int n,i;
    map<string,string> tar;
    for(i=0;i<640000;i++){
        tar[to_string(i)] = to_string(i);
    }
    cout << tar["630000"] <<"\n";
}