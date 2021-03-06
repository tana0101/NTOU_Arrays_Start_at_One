//狀態
dp[i][0]: 點i屬於支配集，並且以點i為根的子樹都被覆蓋了的情況下，支配集中包含的最少點數。
dp[i][1]: 點i不屬於支配集，且以i為根的子樹都被覆蓋，且i被其中不少於1個子結點覆蓋的情況下，支配集包含的最少點數。
dp[i][2]: 點i不屬於支配集，且以i為根的子樹都被覆蓋，且i沒被子結點覆蓋的情況下，支配集包含的最少點數。
// 狀態轉移
dp[i][0] = 1 + Σmin( dp[u][0], dp[u][1], dp[u][2] )
if(i沒有子結點) dp[i][1] = INF
else dp[i][1] = Σmin( dp[u][0], dp[u][1] )
dp[i][2] = Σdp[u][1]