#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 205
#define int long long
using namespace std;

stringstream ss;
bool test(int n){
    string str;
    ss.str("");
    ss.clear();
    ss << hex << n;
    ss >> str;
    map<char,int> mp;
    //cout << str <<"<<\n";
    for(int i=str.size()-1;i>=0;i--){
        mp[str[i]]++;
        if(mp[str[i]]>1){
            return false;
        }
    }
    return true;
}

string to_upper(string str){
    for(int i=0;i<str.size();i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

signed main(){
    io
    int n;
    string str;
    /*cin >> str;
    map<char,int> mp;
    for(int i=str.size()-1;i>=0;i--){
        mp[str[i]]++;
    }*/
    cin >> hex >> n;
    while(++n){
        if(test(n)){    
            string str;
            ss.str("");
            ss.clear();
            ss << hex << n;
            ss >> str;
            cout << to_upper(str) << "\n";
            break;
        }
    }
}