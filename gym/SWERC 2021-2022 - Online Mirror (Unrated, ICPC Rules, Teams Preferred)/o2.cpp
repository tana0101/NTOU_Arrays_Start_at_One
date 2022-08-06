#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct node_c{
    int r,sita1,sita2;
    friend bool operator<(const node_c&a,const node_c&b){
        return a.r<b.r;
    }
};
struct node_s{
    int r1,r2,sita;
};
signed main(){ 
    io
    int t,n;
    cin >> t;
    while(t--){
        vector<node_c> cir;
        vector<node_s> str;
        cin >> n;
        while(n--){
            char ch;
            cin >> ch;
            if(ch=='C'){ // circular
                node_c c;
                cin >> c.r >> c.sita1 >> c.sita2;
                cir.push_back(c);
            }else{ // straight
                node_s s;
                cin >> s.r1 >> s.r2 >> s.sita;
                str.push_back(s);
            }
        }
        sort(cir.begin(),cir.end());
        bool ans=1;
        for(int i=0;i+1<cir.size();i++){ // 兩個最接近的洞有沒有被線擋住
            for(node_s s:str){
                if(cir[i].r >= s.r1 && cir[i+1].r <= s.r2){
                    bool have_str = 0,have_str1=0;
                    //cir[i].sita2 ~ cir[i+1].sita1 順時針
                    // 順
                    if( (cir[i].sita1<=s.sita && s.sita<cir[i+1].sita2) || ( (cir[i].sita1<=s.sita&&s.sita<360)||(0 <= s.sita && s.sita <= cir[i+1].sita2) ) ){
                        have_str=1;
                    }
                    //cir[i].sita1 ~ cir[i+1].sita2 逆時針
                    if( (cir[i+1].sita1<=s.sita && s.sita<cir[i].sita2) || ( (cir[i].sita1<=s.sita&&s.sita<360)||(0 <= s.sita && s.sita <= cir[i+1].sita2) ) ){
                        have_str1=1;
                    }
                    if(have_str&&have_str1){
                        ans = 0;
                        break;
                    }
                }
            }
            if(ans == 0)break;
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}