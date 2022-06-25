const int N = 20000000;//質數表大小
bool sieve[N];
vector<int> prime;
void linear_sieve(){
    for (int i = 2; i < N; i++){
        if (!sieve[i]) prime.push_back(i);
        for (int p : prime){
            if (i * p >= N) break;
            sieve[i * p] = true;
            if (i % p == 0) break;
        }
    }
}