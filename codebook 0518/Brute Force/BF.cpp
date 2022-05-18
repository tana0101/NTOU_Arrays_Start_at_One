/*Brute Force*/
#define MAXN 1<<18+5 //雙倍空間
/*折半枚舉 與 二進制枚舉*/
int main() {
    int n, m, i, temp;
    ll mod, mod_max = 0;
    vector<ll> arr, ans(MAXN,0), ans2(MAXN,0);
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp%m);
    }

    //折半枚舉
    for(int i=0;i<(1<<(n/2));i++){ //2^(n/2)
        for(int j=0;j<n/2;j++){
            if(i>>j&1) //二進制枚舉(選或不選)
                ans[i] = (ans[i] + arr[j]) % m; //前半枚舉
        }
    }
    for(int i=0;i<(1<<(n-n/2));i++){ //2^(n-n/2)
        for(int j=0;j<(n-n/2);j++){
            if(i>>j&1) ans2[i] = (ans2[i] + arr[n/2+j]) % m; //後半枚舉
        }
    }

    //二分維護
    temp = 1<<(n-n/2);
    sort(ans2.begin(), ans2.begin() + temp);
    for(auto i:ans){
        mod_max = max(mod_max, i + *(upper_bound(ans2.begin(), ans2.begin() + temp, m-1-i)-1));
        //mod最大為m-1，配對另一半最優解
    }
    cout << mod_max <<"\n";

    return 0;
}
