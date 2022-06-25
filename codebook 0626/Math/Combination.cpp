#define MXN 1'000'005
#define N 1'000'000
long long fac[MXN], inv[MXN];  
fac[0] = 1; // 0! = 1
for(long long i = 1; i <= N; i++)    
    fac[i] = fac[i-1] * i % MOD; // 階乘
inv[N] = FastPow(fac[N], MOD-2); // 模逆元
for(ll i = N-1; i >=0; i--)
    inv[i] = inv[i+1] * (i+1) % MOD;
// 數字太大請用__int128