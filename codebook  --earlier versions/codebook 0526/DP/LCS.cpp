/*LCS 最長公共子序列*/
void LCS() {
    for (int i = 0; i <= n1; i++) length[i][0] = 0;
    for (int j = 0; j <= n2; j++) length[0][j] = 0;
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (s1[i] == s2[j]) {
                length[i][j] = length[i - 1][j - 1] + 1;
                prev[i][j] = 0;  // 左上方
            }
            else {
                if (length[i - 1][j] < length[i][j - 1]) {
                    length[i][j] = length[i][j - 1];
                    prev[i][j] = 1;  // 左方
                }
                else {
                    length[i][j] = length[i - 1][j];
                    prev[i][j] = 2;  // 上方
                }
            }
    cout << "LCS的長度是" << length[n1][n2];
    cout << "LCS是";
    print_LCS(n1, n2);
}
void print_LCS(int i, int j) {
    if (i == 0 || j == 0) return;
    if (prev[i][j] == 0) {
        print_LCS(i - 1, j - 1);
        cout << s1[i];             // 印出LCS的元素
    }
    else if (prev[i][j] == 1)  // 左方
        print_LCS(i, j - 1);
    else if (prev[i][j] == 2)  // 上方
        print_LCS(i - 1, j);
}