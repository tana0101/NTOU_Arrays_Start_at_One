#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

signed main(){
    io
    int n,temp;
    vector<int> day;
    map<string,int> week;
    week["Mon"] = 1;
    week["Tue"] = 2;
    week["Wed"] = 3;
    week["Thu"] = 4;
    week["Fri"] = 5;
    week["Sat"] = 6;
    week["Sun"] = 0;

    string str;
    cin >> str >> n;
    int today = week[str];
    int mn=1e12;
    
    while(n--){
        cin >> temp;
        int init=(week[str]-(temp%7)+7)%7;
        if(init==1||init==3||init==5){

        }
    }
    cout<<mn<<"\n";
}


/*
Fri 1
60

1 60
3 30
5 0
*/