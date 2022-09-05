/*快速冪*/
ll FastPow(ll x, ll y, ll p) {
    long long ans = 1;
    while (y) {
        if (y & 1)    ans = ans * x % p; //prime
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}