/*--------sort--------*/

//cmp
struct T {int val, num;};
bool cmp(const T &a, const T &b) {
    return a.num < b.num;
}
sort(arr.begin(), arr.end(), cmp);

//operator
struct Point {
    int x, y;
    bool operator<(Point b) {
        if (x != b.x) return x < b.x;
        else return y < b.y;
    }
};
Point arr[n];
sort(arr, arr+n); //二維平面，從小到大排列。