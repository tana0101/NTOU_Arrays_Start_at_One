/*unroll-loops*/
#pragma GCC optimize("O0")//不優化(預設)
#pragma GCC optimize("O1")//優化一點
#pragma GCC optimize("O2")//優化更多
#pragma GCC optimize("O3")//O2優化再加上inline函式優化
#pragma GCC optimize("unroll-loops")
/*常數宣告*/
#define MXN 1'000'005
#define EPS 1e-6
#define INF 0x3f3f3f3f   
#define PI acos(-1)