#include <bits/stdc++.h>
#define int long long
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<string,int> day;

void init(){
    day["Mon"]=1;
    day["Tue"]=2;
    day["Wed"]=3;
    day["Thu"]=4;
    day["Fri"]=5;
    day["Sat"]=6;
    day["Sun"]=7;
}

signed main(){
    io
    init();
    string str;
    int n,mini=INT_MAX;
    cin>>str>>n;
    int now=day[str],pre,start,near;
    while(n--){
        cin>>pre;
        int d=pre%7;
        if(now<=d)start=now+7-d;
        else start=now-d;
        //cerr<<start<<"\n";
        if(start==1){
            near=pre-(pre/91)*91;
            near*=-1;
            int cnt=1;
            while(near<0){
                if(cnt==3)
                    near+=31;
                else
                    near+=30;
                cnt++;
            }
        }
        else if(start==2){
            if(pre>62){
                pre-=62;
                near=pre-(pre/91)*91;
                near*=-1;
                int cnt=1;
                while(near<0){
                    if(cnt==3)
                        near+=31;
                    else
                        near+=30;
                    cnt++;
                }
            }else{
                near=pre*-1;
                int cnt=1;
                while(near<0){
                    if(cnt==2)
                        near+=32;
                    else
                        near+=30;
                    cnt++;
                }
            }
        }else if(start==3){
            if(pre>61){
                pre-=61;
                near=pre-(pre/91)*91;
                near*=-1;
                int cnt=1;
                while(near<0){
                    if(cnt==3)
                        near+=31;
                    else
                        near+=30;
                    cnt++;
                }
            }else{
                near=pre*-1;
                int cnt=1;
                while(near<0){
                    if(cnt==2)
                        near+=31;
                    else
                        near+=30;
                    cnt++;
                }
            }
        }else if(start==4){
            if(pre>32){
                pre-=32;
                near=pre-(pre/91)*91;
                near*=-1;
                int cnt=1;
                while(near<0){
                    if(cnt==3)
                        near+=31;
                    else
                        near+=30;
                    cnt++;
                }
            }else{
                near=pre*-1;
                near+=32;
            }
        }else if(start==5){
            if(pre>31){
                pre-=31;
                near=pre-(pre/91)*91;
                near*=-1;
                int cnt=1;
                while(near<0){
                    if(cnt==3)
                        near+=31;
                    else
                        near+=30;
                    cnt++;
                }
            }else{
                near=pre*-1;
                near+=31;
            }
        }
        mini=min(mini,near);
    }
    cout<<mini<<"\n";
}

/*
Sun 1
31
*/