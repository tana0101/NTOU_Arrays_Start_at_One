// build O(n)
// query O(1)
// double hash
// P = 53,97,193,49157,805306457,1610612741,1e9+9,1e9+7
const ll P1 = 75577;
const ll P2 = 12721;
const ll MOD = 998244353;
pair<ll,ll> Hash[MXN];//Hash[i] 為字串 [0,i] 的hash值
void build(const string& s){
    pair<ll,ll> val = make_pair(0,0);
    for(int i=0; i<s.size(); i++){
        val.first = (val.first * P1 + s[i]) % MOD;
        val.second = (val.second * P2 + s[i]) % MOD;
        Hash[i] = val;
    }
}
pair<ll,ll> query(ll l,ll r){
    pair<ll,ll> q;
    q.first = (Hash[r].first - \ 
    Hash[l-1].first* \ 
    fastpow(P1,r-l+1,MOD)%MOD + MOD)%MOD;
    q.second = ( Hash[r].second - \ 
    Hash[l-1].second* \ 
    fastpow(P2,r-l+1,MOD2)%MOD2 + MOD2 )%MOD2;
    return q;
}