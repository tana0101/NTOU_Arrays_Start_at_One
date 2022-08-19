#include<bits/stdc++.h>
using namespace std;

struct pt{
    int x1,y1,x2,y2;
    pt(){}
    pt(int _x1,int _y1,int _x2,int _y2){
        x1=_x1,y1=_y1,x2=_x2,y2=_y2;
    }
};
int main(){
    int w,h,n,x1,x2,y1,y2;
    cin>>w>>h>>n;
    vector<pt>v;
    vector<int>rid,cid;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if(x1==0&&x2==w)
            rid.push_back(i);
        if(y1==0&&y2==h)
            cid.push_back(i);
        v.push_back(pt(x1,y1,x2,y2));
    }
}