#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

struct node{
    int day;
    int week;
};

bool cmd(node a,node b){
    return a.day<b.day;
}

signed main(){
    io
    int n,temp;
    vector<node> day;
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
    int mx=0;
    
    while(n--){
        cin >> temp;
        node node;
        node.day = temp;
        node.week = (today+14-temp%7)%7;
        if(temp<=30){
            //cerr << temp <<" w="<<node.week<<"\n";
            temp = 30-temp;
            if((today+temp)%7==6){
                temp+=2;
                node.week = 1;
            }else if((today+temp)%7==0){
                temp+=1;
                node.week = 1;
            }else{
                node.week = (node.week+2)%7;
            }
            node.day=temp;
        }else{
            while(1){
                //cerr << temp <<" w="<<node.week<<"\n";
                if(temp <= 30){
                    temp=30-temp;
                    if((node.week+2)%7==6){
                        temp+=2;
                        node.week = 1;
                    }else if((node.week+2)%7==0){
                        temp+=1;
                        node.week = 1;
                    }
                    else node.week = (node.week+2)%7;
                    node.day=temp;
                    //cerr << temp <<" w="<<node.week<<"\n";
                    break;
                }
                if((node.week+2)%7==6){
                    temp-=32;
                    node.week = 1;
                    if(temp<=0){
                        node.day=temp*-1;
                        break;
                    }
                }else if((node.week+2)%7==0){
                    temp-=31;
                    node.week = 1;
                    if(temp<=0){
                        node.day=temp*-1;
                        break;
                    }
                }
                else{
                    temp-=30;
                    node.week = (node.week+2)%7;
                    if(temp<=0){
                        node.day=temp*-1;
                        break;
                    }
                }
            }
        }
        day.push_back(node);
    }
    cout << (*min_element(day.begin(),day.end(),cmd)).day <<"\n";
}