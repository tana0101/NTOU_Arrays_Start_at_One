//預設由大排到小
priority_queue<T> pq 
priority_queue<int, vector<int>, less<int> > pq;
//改成由小排到大
priority_queue<T, vector<T>, greater<T> > pq;  
//自行定義 cmp 排序
priority_queue<T, vector<T>, cmp> pq; 
struct cmp {
    bool operator()(node a, node b) {
        //priority_queue優先判定為!cmp
	//，所以「由大排到小」需「反向」定義
        //實現「最小值優先」
        return a.x < b.x;
    }
};