// freopen()
freopen("intel.in","r",stdin);    // 讀 file.in 檔
freopen("intel.out","w",stdout);  // 寫入 file.out 檔
//二進制"1"的個數
__builtin_popcount(n)   -> int
__builtin_popcountl(n)  -> long int
__builtin_popcountll(n) -> long long
__builtin_popcountll  //換成二進位有幾個1
__builtin_clzll       //返回左起第一個1之前0的個數
__builtin_parityll    //返回1的個數的奇偶性
__builtin_mul_overflow(a,b,&h) //回傳a*b是否溢位
//陣列處理
sort(arr,arr+n);
reverse(arr,arr+n);
*min_element(arr, arr+n); //value
min_element(arr, arr+n) - arr; //index
*lower_bound(arr, arr+4, c) << '\n'; //第一個大於等於c
*upper_bound(arr, arr+4, c) << '\n'; //第一個大於c
fill(arr, arr+3, 123);
//輸出
cout << fixed << setprecision(10);
cout << setw(n) << setfill(c);
//迭代器
T.begin()
T.end()
T.rbegin() //逆序迭代器
T.rend() //逆序迭代器
T.find() //可用於set,map的earse()。