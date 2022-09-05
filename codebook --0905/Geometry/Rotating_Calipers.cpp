// 最遠兩點配對
double FarthestPair(vector<Pt> arr){
	double ret = 0;
	for (int i = 0, j = i + 1; i < arr.size(); i++){
		while (distance(i, j) < distance(i, (j + 1) % arr.size())){
			j = (j + 1) % arr.size();
		}
		ret = max(ret, distance(i, j));
	}
	return ret;
}
// 點是否凸包內
bool in_hull(vector<Pt> &hull, Pt p){
	int flag = 0;
	for (int i = 0; i < hull.size(); i++){ 
		if (cross(p, hull[i], hull[(i + 1) % hull.size()]) > 0){ 
			//與凸包上前後兩點作外積，如果夾角在0~180度內，則在內側。
			flag++;
		}
	}
	if (flag == hull.size())
		return true;
	else
		return false;
}

// 線找點最短距離
ld rot(vector<Pt> hull){
	ld mn = 2.0 * r;
	int n = hull.size();
	hull.pb(hull[0]);
	for (int i = 0, j = i + 2; i < n; i++){
		//平行四邊形面積 除以 底 ＝ 高
		ld area = abs(cross(hull[i], hull[i + 1], hull[j]));
		ld base = abs(dis(hull[i], hull[i + 1]));
		while (area <= abs(cross(hull[i], hull[i + 1], hull[(j + 1) % n]))){
			j = (j + 1) % n;
			area = abs(cross(hull[i], hull[i + 1], hull[j]));
		}
		mn = min(mn, area / base);
	}
	return mn;
}
// 最大三角形
ld solve(vector<Pt> arr){
	ld ret = 0;
	for (int i = 0; i < arr.size(); i++)
		for (int j = i + 1; j < arr.size(); j++)
			for (int k = j + 1; k < arr.size(); k++)
				ret = max(ret, area(i, j, k));
	return ret;
}
// 最大四邊形
ll solve(){//兩倍面積
	ll ret = 0;
	for (int i = 0; i < hull.size(); i++){
		int k = (i + 1) % hull.size(), k2 = (i + 3) % hull.size();
		for (int j = i + 2; j <= i + hull.size() - 2; j++){
			while (area(i, j % hull.size(), k) < area(i, j % hull.size(), (k + 1) % hull.size())){
				k = (k + 1) % hull.size();
			}
			while (area(i, j % hull.size(), k2) < area(i, j % hull.size(), (k2 + 1) % hull.size())){
				k2 = (k2 + 1) % hull.size();
			}
			ret = max(ret, area(i, j % hull.size(), k) + area(i, j % hull.size(), k2));
		}
	}
	return ret;
}