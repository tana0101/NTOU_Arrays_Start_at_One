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
        if(temp==30){
            int wait=0;
            if(str=="Sat")wait+=2;
            else if(str=="Sun")wait+=1;
            mn=min(mn,wait);
        }else{
            int init=(week[str]-(temp%7)+7)%7;
            while(temp>=30){
                init=(init+2)%7;
                if(init==6){
                    temp-=2;
                    init=1;
                }
                else if(init==0){
                    temp-=1;
                    init=1;
                }
                temp-=30;
            }
            int remain=30-temp;
            int days=remain%7;
            int d=(week[str]+days)%7;
            if(d==6)remain+=2;
            else if(d==0)remain+=1;
            mn=min(mn,remain);
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