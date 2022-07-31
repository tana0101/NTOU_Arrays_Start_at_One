#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    map<string,int>mp;
    for(int i=0;i<n;i++){
        cin>>s;
        mp[s]++;
    }
    vector<pair<string,int>>v;
    for(auto it:mp){
        v.push_back(it);
    }
}