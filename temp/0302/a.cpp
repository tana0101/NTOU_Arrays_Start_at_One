#include<bits/stdc++.h>
#define INF -1
using namespace std;

    int table[10]={42,11,12,13,21,22,23,31,32,33};
    int index_[5][4]={INF, INF, INF, INF, INF, 1,  2,  3, INF, 4,  5,  6, INF, 7,  8,  9, INF, INF, 0,  INF};

bool test(int k){
    bool flag=0;
    int temp;
    string cur, str;
    stringstream ss;
    ss << k;
    ss >> str;
    if(str.size()==1)return true;

    temp = table[int(str[0]-'0')];
    ss.clear();
    ss.str("");
    ss << temp;
    ss >> cur;
    //cout << "cur=" <<cur <<"\n";
    for(int i = cur[0]-'0'; i<=4; i++){ //down
            //cout <<"i="<<i<<"\n";
        for(int j = cur[1]-'0'; j<=3; j++){ //right
             //cout <<"j="<<j<<"\n";
            if(i == 4 &&(j == 1 || j == 3))continue;
            if(index_[i][j] == int(str[1]-'0')){
                flag=1;
                //cout << "-----yes" <<"\n\n\n";
                break;
            }
        }
        if(flag)break;
    }
    if(flag&&str.size()==3){
        temp = table[int(str[1]-'0')];
        ss.clear();
        ss.str("");
        ss << temp;
        ss >> cur;
        flag=0;
        //cout << "cur=" <<cur <<"\n";
        for(int i = cur[0]-'0'; i<=4; i++){ //down
                cout <<"i="<<i<<"\n";
            for(int j = cur[1]-'0'; j<=3; j++){ //right
                //cout <<"j="<<j<<"\n";
                if(i == 4 &&(j == 1 || j == 3))continue;
                if(index_[i][j] == int(str[2]-'0')){
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
    }
    if(flag)return true;
    else return false;
}

int main(){

    int t, k, i;
    cin >> t;

    while(t--){
        cin >> k;
        i=0;
        int x=10;
        while(1){
            //cout << "go = "<<k+i<<"\n";
            if(test(k+i)){
                cout << k+i <<"\n";
                break;
            }
            //cout << "go = "<<k-i<<"\n";
            if(test(k-i)){
                cout << k-i <<"\n";
                break;
            }
            i++;
        }
    }
    return 0;
}
