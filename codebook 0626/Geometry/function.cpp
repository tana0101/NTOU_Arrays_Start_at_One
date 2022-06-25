//是否三點共線
bool collinearity(const Pt& a, const Pt& b, const Pt& c){ 
    return (b-a)^(c-a) < EPS; //外積為0: ==0
}
//判斷點是否在線段上
bool inLine(const Pt& p, const Line& li){ 
    return collinearity(li.st, li.ed, p) && (li.st-p)*(li.ed-p) < EPS; //內積為負: <=0
}
//平行四邊形面積
ll areaPt(Pt i, Pt j, Pt k){ 
    return abs(cross(i, j, k));
}
//兩點距離
ld distance(Pt i,Pt j){
    Pt vt = i - j;
    return sqrt((ld)(vt.x)*(vt.x)+(ld)(vt.y)*(vt.y));
}
ld distance(int i,int j){
    Pt vt = p[i]-p[j];
    return sqrt((ld)(vt.x)*(vt.x)+(ld)(vt.y)*(vt.y));
}
// 輸出
round(double x); //四捨五入至整數
cout << fixed << setprecision(11); //精度
void print(ll x){ //兩倍面積輸出判斷
    if(x&1)
        cout << (x>>1) << ".5\n";
    else
        cout << (x>>1) <<"\n";
}