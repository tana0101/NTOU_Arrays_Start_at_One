/*karatsuba 快速乘法*/
// Get size of the numbers
int getSize(ll num){
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}
ll karatsuba(ll X, ll Y){
    // Base Case
    if (X < 10 && Y < 10)
        return X * Y;
    // determine the size of X and Y
    int size = fmax(getSize(X), getSize(Y));
    // Split X and Y
    int n = (int)ceil(size / 2.0);
    ll p = (ll)pow(10, n);
    ll a = (ll)floor(X / (double)p);
    ll b = X % p;
    ll c = (ll)floor(Y / (double)p);
    ll d = Y % p;
    // Recur until base case
    ll ac = karatsuba(a, c);
    ll bd = karatsuba(b, d);
    ll e = karatsuba(a + b, c + d) - ac - bd;
    // return the equation
    return (ll)(pow(10 * 1L, 2 * n) * ac + pow(10 * 1L, n) * e + bd);
}