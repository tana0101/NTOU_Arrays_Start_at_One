int factor[MXN];
for(ll i = 2; i <= N; i++){
    if(factor[i])    continue;
    for(ll j = i*i; j <= N; j+=i){
        factor[j] = i;
    }
}
map<int, int> factorization(int x){
    map<int, int> prime;
    while(factor[x]){
        prime[factor[x]]++;
        x /= factor[x];
    }
    prime[x]++;
    return prime;
}