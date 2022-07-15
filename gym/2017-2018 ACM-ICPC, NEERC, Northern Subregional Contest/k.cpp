#include<bits/stdc++.h>

using namespace std;


signed main() {
    
    freopen("kotlin.in","r",stdin);    // 讀 file.in 檔
    freopen("kotlin.out","w",stdout);  // 寫入 file.out 檔
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char> > mp(h + 1, vector<char>(w + 1, '.'));
    if ((h - (h / 2)) * (w - (w / 2)) < n) {
        cout << "Impossible\n";
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i * (n / i) == n) {
                if (i + (i - 1) <= h && (n / i) + (n / i - 1) <= w) {
                    for (int m = 1, cnt = 1; m <= h; m++) {
                        if (cnt == i)break;
                        if (!(m & 1)) {
                            for (int j = 1; j <= w; j++) {
                                mp[m][j] = '#';
                            }
                            cnt++;
                        }
                    }
                    for (int m = 1, cnt = 1; m <= w; m++) {
                        if (cnt == (n / i))break;
                        if (!(m & 1)) {
                            for (int j = 1; j <= h; j++) {
                                mp[j][m] = '#';
                            }
                            cnt++;
                        }
                    }
                    break;
                }
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << mp[i][j];
            }
            cout << "\n";
        }
    }
}