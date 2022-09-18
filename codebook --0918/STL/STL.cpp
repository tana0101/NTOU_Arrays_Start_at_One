// freopen()
freopen("intel.in","r",stdin);    // 讀 file.in 檔
freopen("intel.out","w",stdout);  // 寫入 file.out 檔

//輸出
cout << fixed << setprecision(10);
cout << setw(n) << setfill(c);

// math
abs(x);
pow(x);
sqrt(x);
__gcd(x, y);//c++14
lcm(x,y);//c++17
__lg(x)  //以2為底數
log(x)	 //以e為底數
log10(x) //以10為底數
do {     //排列
    cout << s << "\n";
} while (next_permutation(s.begin(), s.end()));
prev_permutation(s.begin, s.end()) //大到小
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());


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

// bitset
bitset<30>(string)
b.set();   
b.reset();  
s = b.to_string();
unsigned long x = b.to_ullong();
b.any();//判別是否有 '1'
b.none();//判別是否沒 '1'
cnt = b.count();// 判別 '1' 之個數
cnt = b.size() - b.count();//判別 '0' 之個數
__builtin_popcount(n)   -> int
__builtin_popcountl(n)  -> long int
__builtin_popcountll(n) -> long long
__builtin_popcountll  //換成二進位有幾個1
__builtin_clzll       //返回左起第一個1之前0的個數
__builtin_parityll    //返回1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) //回傳a*b是否溢位