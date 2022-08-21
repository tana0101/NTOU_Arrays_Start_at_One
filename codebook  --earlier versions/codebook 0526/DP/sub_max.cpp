/*最大非連續子序列和*/
int sub_max(int* list,int sub_len) { //子序列長度sub_len
    if (sub_len == 3) {
        return list[0] + list[2];
    }
    int temp[10005];
    for (int m = 0; m < sub_len; m++) {
        temp[m] = list[m];
    }
    temp[0] = list[0];
    temp[1] = list[1] > list[0] ? list[1] : list[0];
    for (int i = 2; i < sub_len; i++) {
        temp[i] = max(max(temp[i], temp[i - 1]), temp[i - 2] + list[i]);
    }
    return temp[sub_len - 1];
}
int main() {

    int n, m;
    int list[10005];

    cin >> n;

    for (m = 0; m < n; m++) {
        cin >> list[m];
    }
    sub_len = m;//list大小,global變數

    cout << sub_max(list, sub_len);

    return 0;
}