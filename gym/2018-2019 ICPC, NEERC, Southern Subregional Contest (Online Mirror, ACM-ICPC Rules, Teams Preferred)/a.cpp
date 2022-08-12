#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pb push_back
#define ep emplace
#define all(x) x.begin,x.end
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long


using namespace std;

int sol(int n){
    int sum =0;
    string str = to_string(n);
    for(int i=0;i<str.size();i++){
        sum += int(str[i]-'0');
    }
    if(sum>=10){
        return sol(sum);
    }else return sum;
}

signed main(){
    io
    int d,s,n,i;
    cin >> d >> s;
    for(i=1;i<=30;i++){
        cout << d*i <<"\t"<<i <<"\t"<<sol(i)<<"\t"<< sol(d*i) <<"\n";
    }
}

(a+b+c+d+e) % x = 0 
=
(a%x + b%x + c%x + d%x + e%x)%x = 0

13 50
699998

ax+by=gcd(a,b)

699998%13=0
50%13=11
(6%13 + 9%13 ...=50)%13 = 11