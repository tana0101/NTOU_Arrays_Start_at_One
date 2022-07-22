#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define ep emplace
#define all(x) x.begin(),x.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define MAXN 10005
using namespace std;

int r;
struct Pt{
    ll x,y;
    Pt(){}
    Pt(ll _x,ll _y){
        x=_x;y=_y;
    }
    Pt operator-(const Pt &a) const{
        return Pt(x-a.x,y-a.y);
    }
    bool operator<(const Pt &a) const{
        return x<a.x||(x==a.x&&y<a.y);
    }
    friend bool operator==(const Pt &a,const Pt &b) {
        return (a.x==b.x)&&(a.y==b.y);
    }
    friend int cross(const Pt &o,const Pt &a,const Pt &b) {
        Pt l=o-a;
        Pt r=o-b;
        return l.x*r.y-l.y*r.x;
    }
    friend int cross(const Pt &a,const Pt &b) {
        return a.x*b.y-a.y*b.x;
    }
};

vector<Pt> gethull(vector<Pt> hull){
    sort(all(hull));
    int top=0;
    vector<Pt> stk;
    for(int i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=0){
            stk.pop_back(),top--;
        }
        stk.pb(hull[i]);
        top++;
    }
    for(int i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<=0){
            stk.pop_back(),top--;
        }
        stk.pb(hull[i]);
        top++;
    }
    stk.pop_back();
    return stk;
}
ll dis(Pt i,Pt j){ // dis^2
    Pt vt = i-j;
    return vt.x*vt.x + vt.y*vt.y;
}
ld rot(vector<Pt> hull){
    ld mn = 2*r*2*r;
    for(int i=0,j=i+2;i<hull.size();i++){
        while(cross(hull[i],hull[i+1],hull[j])<cross(hull[i],hull[i+1],hull[(j+1)%hull.size()])){
            j=(j+1)%hull.size();
        }
        ld area = cross(hull[i],hull[i+1],hull[j]);
        cout << area <<"\n";
        mn = min(mn,(area/(ld)(dis(hull[i],hull[j]))));
    }
    return mn;
}

signed main(){
    io
    int n,i,x,y;
    cin >> n >> r;
    vector<Pt> c; //candle
    for(i=0;i<n;i++){
        cin >> x >> y;
        c.pb({x,y});
    }
    vector<Pt> hull = gethull(c);
    cout << fixed << setprecision(11)<<sqrt(rot(hull)) <<"\n";
}