// 旋轉卡尺
// 最遠兩點配對
double FarthestPair(vector<Pt> arr){
    double ret=0;
    for(int i=0,j=i+1;i<arr.size();i++){
        while(distance(i,j)<distance(i,(j+1)%arr.size())){
            j=(j+1)%arr.size();
        }
        ret=max(ret,distance(i,j));
    }
    return ret;
}
// 最大三角形
ld solve(vector<Pt> arr){
    ld ret=0;
    for(int i=0;i<arr.size();i++)
        for(int j=i+1;j<arr.size();j++)
            for(int k=j+1;k<arr.size();k++)
                ret = max(ret,area(i,j,k));
    return ret;
}
// 最大四邊形
ll solve(){ //兩倍面積
    ll ret=0;
    for(int i=0;i<hull.size();i++){
        int k=(i+1)%hull.size(),k2=(i+3)%hull.size();
        for(int j=i+2;j<=i+hull.size()-2;j++){
            while(area(i,j%hull.size(),k)<area(i,j%hull.size(),(k+1)%hull.size())){
                k=(k+1)%hull.size();
            }
            while(area(i,j%hull.size(),k2)<area(i,j%hull.size(),(k2+1)%hull.size())){
                k2=(k2+1)%hull.size();
            }
            ret=max(ret,area(i,j%hull.size(),k)+area(i,j%hull.size(),k2));
        }
    }
    return ret;
}