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
struct node_layer{
    int intheda1,intheda2,outtheda1,outtheda2;
    int inner,outer;
    vector<int> stheda;
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
                // cout << c.r <<" "<< c.sita1 <<" "<< c.sita2 <<"\n";
                if(c.sita1>c.sita2)swap(c.sita1,c.sita2);
                cir.push_back(c);
            }else{ // straight
                node_s s;
                cin >> s.r1 >> s.r2 >> s.sita;
                // cout << s.r1 <<" "<<s.r2<<" "<<s.sita<<"\n";
                str.push_back(s);
            }
        }
        sort(cir.begin(),cir.end());
        vector<node_layer>lay;
        for(int i=0;i<cir.size() - 1;i++){
            node_layer ly;
            ly.intheda1=cir[i].sita1,ly.intheda2=cir[i].sita2;
            ly.outtheda1=cir[i+1].sita1,ly.outtheda2=cir[i+1].sita2;
            ly.inner=cir[i].r,ly.outer=cir[i+1].r;
            lay.push_back(ly);
        }
        for(int i=0;i<str.size();i++){
            for(int j=0;j<lay.size();j++){
                if(lay[j].inner>=str[i].r1&&lay[j].outer<=str[i].r2){
                    lay[j].stheda.push_back(str[i].sita);
                }
            }
        }
        bool ans=1;
        for(auto x:lay){
            // (cir[i].sita1<=s.sita && s.sita<cir[i+1].sita2) || ( (cir[i].sita1<=s.sita&&s.sita<360)||(0 <= s.sita && s.sita <= cir[i+1].sita2) )
            int circle[360]={};
            for(auto stheda:x.stheda){
                circle[stheda]=-1;
            }
            int fail1=0,fail2=0;
            for(int i=(x.intheda1<x.outtheda2?x.intheda1+360:x.intheda1);i>=x.outtheda2;i=(i-1+360)%360){
                if(circle[i%360]==-1){
                    fail1=1;
                    break;
                }
            }
            for(int i=(x.intheda2>x.outtheda1?x.intheda2-360:x.intheda2);i<=x.outtheda1;i=(i+1)%360){
                if(circle[(i+360)%360]==-1){
                    fail2=1;
                    break;
                }
            }
            if(fail1 && fail2){
                ans = 0;
                break;
            }
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}