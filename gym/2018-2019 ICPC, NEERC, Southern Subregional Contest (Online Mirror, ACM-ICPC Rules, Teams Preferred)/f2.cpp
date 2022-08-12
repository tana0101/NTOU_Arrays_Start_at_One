#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;

int main() {
    io
    ll n, af, tot=0, ts=0;
    string s;
    cin >> n;
    vector<int>alice,bob,non;
    for(int i=0;i<n;i++){
        cin>>s>>af;
        if(s=="11"){
            tot+=af;
            ts++;
        }else if(s=="10"){
            alice.push_back(af);
        }else if(s=="01"){
            bob.push_back(af);
        }else{
            non.push_back(af);
        }
    }
    sort(alice.begin(),alice.end(),greater<int>());
    sort(bob.begin(),bob.end(),greater<int>());
    sort(non.begin(),non.end(),greater<int>());
    for (int i = 0; i < n; i++) {
        tot += alice[i];
        tot += bob[i];
    }
    int al=ts,bo=ts;
    int m=ts;
    int tot_1 = tot,tot_2 = tot;
    for(int i=0;i<alice.size();i++){
        m++;
        tot_1+=alice[i];
        al++;
    }
    for(int i=0;i<bob.size();i++){
        m++;
        tot_2+=bob[i];
        bo++;
    }
    if(((al*2)>=m) && ((bo*2)>=m)){
        cout << max(tot_1,tot_2)<<"\n";
    }else{
        cout <<"0\n";
    }
}