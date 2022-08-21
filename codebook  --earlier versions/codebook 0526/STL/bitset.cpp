/*--------bitset--------*/
//init
string s = "1001101";
bitset<10> b(s);

b.set();    //每個位元設 '1'
b.reset();  //每個位元設 '0'
b[pos] = 1;

//轉換
s = b.to_string();
unsigned long x = b.to_ulong();

//overload
b = !b0;
b = b0 & b1;
b = b0 | b1;
b = b0 ^ b1;

//shift
new_b = b << 2;
new_b = b >> 2;

//sum
b.any();//判別是否有 '1'
b.none();//判別是否沒 '1'
cnt = b.count();// 判別 '1' 之個數
cnt = b.size() - b.count();//判別 '0' 之個數
