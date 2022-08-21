/*前置作業*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
cin.tie(0);cout.tie(0);
ios_base::sync_with_stdio(false);
/*unroll-loops*/
#pragma GCC optimize("O0")//不優化(預設)
#pragma GCC optimize("O1")//優化一點
#pragma GCC optimize("O2")//優化更多
#pragma GCC optimize("O3")//O2優化再加上inline函式優化
#pragma GCC optimize("unroll-loops")
/*常數宣告*/
// 數字中可以加 ' 方便看出幾位數
#define MXN 1'000'005
// 1e-6 為科學記號 代表 1 * 10^-6
#define EPS 1e-6
// 0x3f3f3f3f為一個接近10^9的數字0x為16進位
#define INF 0x3f3f3f3f    
// acos(-1) 等同圓周率
#define PI acos(-1)  
/*位元運算*/
if(x&1) cout<<奇數;
else    cout<<偶數;
x <<= 1    //將x左移1，等同 *2
x >>= 2    //將x右移2，等同 /4