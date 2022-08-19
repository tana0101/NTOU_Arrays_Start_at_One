#include<bits/stdc++.h>
#define ll long long
#define INF 1e15
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>>dis(n + 1, vector<ll>(n + 1)), dp(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dis[i][j];
        }
    }
    vector<int>vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j += 2) {
                if (!vis[j]) {
                    dp[i][j] = dp[i - 1][i - 1] + dis[i - 1][j];
                }
            }
        }
        else {
            for (int j = 1; j <= n; j += 2) {
                dp[i][i] = min(dp[i][i], dp[i - 1][j] + dis[j][i]);
            }
        }
    }
    ll mx = INF;
    for (int i = 1; i <= n; i++) {
        mx = min(mx, dp[n][i]);
    }
    cout << mx << "\n";
}