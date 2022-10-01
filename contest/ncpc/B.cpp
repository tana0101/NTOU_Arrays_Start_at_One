#include<bits/stdc++.h>
#define int long long
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

struct air{
    int id,x,y,alt;
    air(){}
    air(int _id,int _x,int _y,int _alt){
        id=_id;
        x=_x;
        y=_y;
        alt=_alt;
    }
};
struct warn{
    int ida,idb,dis,alt;
    warn(){}
    warn(int _ida,int _idb,int _dis,int _alt){
        ida=_ida;
        idb=_idb;
        dis=_dis;
        alt=_alt;
    }
};
int dis(air a,air b){
    return abs((a.x-b.x)*(a.x-b.x))+abs((a.y-b.y)*(a.y-b.y));
}
int diff(air a,air b){
    return abs(a.alt-b.alt);
}
bool cmp(warn a,warn b){
    if(a.ida!=b.ida)return a.ida<b.ida;
    else return a.idb<b.idb;
}
signed main(){
    io
    int t;
    cin>>t;
    while(t--){
        int n,dxy,dalt,id,x,y,alt;
        cin>>n>>dxy>>dalt;
        dxy*=dxy;
        vector<air> craft;
        for(int i=0;i<n;i++){
            cin>>id>>x>>y>>alt;
            craft.push_back(air(id,x,y,alt));
        }
        vector<warn> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dis(craft[i],craft[j])<=dxy){
                    ans.push_back(warn(min(craft[i].id,craft[j].id),max(craft[i].id,craft[j].id),dis(craft[i],craft[j]),diff(craft[i],craft[j])));
                }else if(dis(craft[i],craft[j])<=(dxy*4)&&diff(craft[i],craft[j])<=dalt){
                    ans.push_back(warn(min(craft[i].id,craft[j].id),max(craft[i].id,craft[j].id),dis(craft[i],craft[j]),diff(craft[i],craft[j])));
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<(int)ans.size();i++){
            cout<<ans[i].ida<<" "<<ans[i].idb<<" "<<(int)ceil(sqrt(ans[i].dis))<<" "<<ans[i].alt<<"\n";
        }
        cout<<ans.size()<<"\n";
    }
}