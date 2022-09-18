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