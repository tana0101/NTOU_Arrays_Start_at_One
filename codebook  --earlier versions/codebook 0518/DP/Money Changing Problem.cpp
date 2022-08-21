/*Money Changing Problem*/
// n：用第0種到第n種錢幣來湊得價位。
// m：欲湊得的價位值。
// c(n, m)：用第0種到第n種錢幣湊得價位m的湊法數目。
// price[n]：第n種錢幣的面額大小。

// 能否湊得某個價位（ Money Changing Problem ）
// 給定許多種不同面額的錢幣，
// 能否湊得某個價位？
// 每種面額的錢幣都無限供應。

int price[5] = {5, 2, 6, 11, 17};// 錢幣面額
bool c[1000+1];
// 這些面額湊不湊得到價位 m
void change(int m){
    memset(c, false, sizeof(c));
    c[0] = true;

    // 依序加入各種面額
    for (int i = 0; i < 5; ++i)
        // 由低價位逐步到高價位
        for (int j = price[i]; j <= m; ++j)
            // 湊、湊、湊
            c[j] |= c[j-price[i]];

    if (c[m])
        cout << "湊得到";
    else
        cout << "湊不到";
}
// 湊得某個價位的湊法總共幾種（ Coin Change Problem ）
void change(int m){
    memset(c, 0, sizeof(c));
    c[0] = 1;

    for (int i = 0; i < 5; ++i)
        for (int j = price[i]; j <= m; ++j)
            c[j] += c[j-price[i]];

    cout << "湊得價位" << m;
    cout << "湊法總共" << c[m] << "種";
}
// 湊得某個價位的最少錢幣用量（ Change-Making Problem ）
// c(n, m)：用第0種到第n種錢幣湊得價位m，最少所需要的錢幣數量。
void change(int m){
    memset(c, 0x7f, sizeof(c));
    c[0] = 0;

    for (int i = 0; i < 5; ++i)
        for (int j = price[i]; j <= m; ++j)
            c[j] = min(c[j], c[j-price[i]] + 1);

    cout << "湊得價位" << m;
    cout << "最少需（只）要" << c[m] << "個錢幣";
}
// 湊得某個價位的錢幣用量，有哪幾種可能性。
void change(int m){
    memset(c, 0, sizeof(c));
    c[0] = 1;

    for (int i = 0; i < 5; ++i)
        for (int j = price[i]; j <= m; ++j)
            // 錢幣數量加一，每一種可能性都加一。
            c[j] |= c[j-price[i]] << 1;

    for (int i = 1; i <= 63; ++i)
        if (c[m] & (1 << i))
            cout << "用" << i << "個錢幣可湊得價位" << m;
}
// 能否湊得某個價位，但是錢幣限量供應！
int price[5] = {5, 2, 6, 11, 17};
int number[5] = {4, 5, 5, 3, 2}; // 各種錢幣的供應數量
bool c[1000+1];
void change(int m){
    memset(c, 0, sizeof(c));
    c[0] = true;
    for (int i = 0; i < 5; ++i)
        // 各種餘數分開處理
        for (int k = 0; k < price[i]; ++k){
            int left = number[i]; // 補充彈藥
            // 由低價位到高價位
            for (int j = k; j <= m; j += price[i])
                // 先前的面額已能湊得，當前面額可以省著用。
                if (c[j])
                    left = number[i];   // 補充彈藥
                // 過去都無法湊得，一定要用目前面額硬湊。
                else if (left > 0){
                    left--; // 用掉一個錢幣
                    c[j] = true;
                }
        }
    if (c[m])
        cout << "湊得到";
    else
        cout << "湊不到";
}
// Cashier's Algorithm
// 買東西找回最少硬幣。
int price[5] = {50, 20, 10, 4, 2};  // 面額由大到小排列
void cashier(int n){ // n 是總共要找的錢。
    int c = 0;
    for (int i=0; i<5; ++i)
        while (n >= price[i])
        {
            n -= price[i];  // 找了 price[i] 元
            c++;
        }

    if (n != 0)
        cout << "找不出來";
    else
        cout << "找了" << c << "個錢幣";
}
