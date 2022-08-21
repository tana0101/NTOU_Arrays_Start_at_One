/*--------常用工具--------*/
swap(a,b);
min(a,b);
max({ a, b, c });

//二進制"1"的個數
__builtin_popcount(n)   -> int
__builtin_popcountl(n)  -> long int
__builtin_popcountll(n) -> long long

//math
abs(x);
pow(x);
sqrt(x);
__gcd(x, y);
__lg(x)  //以2為底數
log(x)	 //以e為底數
log10(x) //以10為底數
do {     //排列組合
    cout << s << "\n";
} while (next_permutation(s.begin(), s.end()));


//陣列處理
sort(arr,arr+n);
reverse(arr,arr+n);
*min_element(arr, arr+n); //value
min_element(arr, arr+n) - arr; //index
*lower_bound(arr, arr+4, c) << '\n'; //第一個大於等於c
*upper_bound(arr, arr+4, c) << '\n'; //第一個大於c
//填充 arr[0]=123 arr[1]=123 arr[2]=123
fill(arr, arr+3, 123);

//輸出
//四捨五入 或是更高精度(int)10 * 位數 + 0.5
cout << fixed << setprecision(10);
//寬度n 用char(c)填補
cout << setw(n) << setfill(c) << ;

//迭代器
T.begin()
T.end()
T.rbegin() //逆序迭代器
T.rend() //逆序迭代器
T.find() //可用於set,map的earse()。
