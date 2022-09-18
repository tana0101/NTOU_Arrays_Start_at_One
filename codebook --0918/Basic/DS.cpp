unordered_map<type,type> u_map; //O(1)
unordered_set<int> u_set;
multiset<int> st;
priority_queue<T, vector<T>, less<T>> pq;
priority_queue<T, vector<T>, greater<T>> pq;  
priority_queue<T, vector<T>, cmp> pq; 
struct cmp {
    bool operator()(node a, node b) {
    //priority_queue優先判定為!cmp
	//，所以「由大排到小」需「反向」定義
    //實現「最小值優先」
        return a.x < b.x;
    }
};
// erase操作
iterator erase (it position);//刪除指定元素
iterator erase (it first, it last);//刪除指定範圍
// 刪除指定數值
auto it = find(p.begin(), p.end(), val);
p.erase(it);
// 刪除所有指定數值
p.erase(remove(p.begin(), p.end(), val), p.end());