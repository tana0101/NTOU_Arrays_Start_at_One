/*ax+by=gcd(a,b) 一組解*/
ll a, b, x, y;
ll exgcd(ll a, ll b, ll& x, ll& y) {    
    if (b) {
        ll d = exgcd(b, a % b, y, x);
        return y -= a / b * x, d;
    }
    return x = 1, y = 0, a;
}