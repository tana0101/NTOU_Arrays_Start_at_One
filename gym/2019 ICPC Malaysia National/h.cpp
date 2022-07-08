#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Pt{
    ll x,y;
    Pt(){}
    Pt(ll _x,ll _y){
        x=_x;y=_y;
    }
    Pt operator+(const Pt &a) const{
        return Pt(x+a.x,y+a.y);
    }
    Pt operator-(const Pt &a) const{
        return Pt(x-a.x,y-a.y);
    }
    Pt operator*(const ld &a) const{
        return Pt(x*a,y*a);
    }
    Pt operator/(const ld &a) const{
        return Pt(x/a,y/a);
    }
    ll operator*(const Pt &a) const{
        return x*a.x+y*a.y;
    }
    ll operator^(const Pt &a) const{
        return x*a.y-y*a.x;
    }
    bool operator<(const Pt &a) const{
        return x<a.x ||(x==a.x&&y<a.y);
    }
    friend int cross(const Pt& o,const Pt& a,const Pt& b){
        Pt lhs = o-a;
        Pt rhs = o-b;
        return lhs.x*rhs.y - lhs.y*rhs.x;
    }
    friend bool operator==(const Pt &l,const Pt &r){
        return (r.x==l.x && r.y==l.y);
    }
};
vector<Pt> convex_hull(vector<Pt> hull){
    sort(hull.begin(),hull.end());
    int top=0;
    vector<Pt> stk;
    for(int i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<0){
            stk.pop_back(),top--;
        }
        stk.push_back(hull[i]);
        top++;
    }
    for(int i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<0) 
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    stk.pop_back();
    return stk;
}
bool inhull(){
    
}
int main(){
    io
    int t,i,cs=1,c,p,x,y;
    cin >> t;
    while(t--){
        cout << "Case "<<cs++<<"\n";
        vector<Pt> pt;
        cin >> c >> p;
        for(i=0;i<c;i++){
            cin >> x >> y;
            pt.push_back(Pt(x,y));
        }
        vector<Pt> pt2; //black
        vector<Pt> hull = convex_hull(pt); //blue hull
        for(auto p1:hull){
            cout << p1.x << " " <<p1.y<<"\n";
        }
        cout << hull[0].x << " "<<hull[0].y;
        for(i=0;i<p;i++){
            cin >> x >> y;
            pt.push_back(Pt{x,y}); // all point
            pt2.push_back(Pt{x,y});
        }
        cout << "\n";
        for(auto p1:pt2){
            if(inhull){
                cout << " is safe!\n";
            }else cout << " is unsafe!\n";
        }
        cout << "\n";
    }
}