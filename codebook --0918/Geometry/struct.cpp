struct Pt{ 
    ld x, y; 
};
struct Line{ 
    Pt st, ed; 
};
struct Circle{ 
    Pt o; // 圓心
    ld r; // 半徑
};
struct poly{
    int n; // n 邊形
    vector<Pt> pts; 
};
struct Pt {
  ll x, y; // ll or ld
  Pt(){}
  Pt(ll _x,ll _y){ x=_x, y=_y; }
  
  Pt operator+(const Pt &a) const{
    return Pt(x+a.x, y+a.y);
  }
  Pt operator-(const Pt &a) const{
    return Pt(x-a.x, y-a.y);
  }
  Pt operator*(const ld &a) const{
    return Pt(x*a, y*a);
  }
  Pt operator/(const ld &a) const{
    return Pt(x/a, y/a);
  }
  ll operator*(const Pt &a) const{ //內積
    return x*a.x + y*a.y;
  }
  ll operator^(const Pt &a) const{ //外積
    return x*a.y - y*a.x;
  }
  bool operator<(const Pt &a) const{
    return x < a.x || (x == a.x && y < a.y);
  }
  friend int cross(const Pt& o,const Pt& a,const Pt& b){ //向量外積
    Pt lhs = o-a, rhs = o-b;
    return lhs.x*rhs.y - lhs.y*rhs.x;
  }
  friend bool operator ==(const Pt& lhs,const Pt& rhs){
    return (rhs.x==lhs.x && rhs.y==lhs.y);
  }
};