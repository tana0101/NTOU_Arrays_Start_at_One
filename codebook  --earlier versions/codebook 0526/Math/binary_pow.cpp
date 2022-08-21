/*快速冪*/
ll mypow(ll x, ll y, ll p) {
    long long ans = 1;
    while (y) {
        if (y & 1)    ans = ans * x % p;    //prime
        x = x * x % p;    //每次把自己平方
        y >>= 1;    //每次右移一格
    }
    return ans;
}