#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int sum, nums[10];
int valid(int cur, int step) {
    for (int i = 0; i < 10; i++) {
        if (i == cur || (step == 0 && i == 0)) {
            continue;
        }
        if (nums[i] != 0) {
            nums[i]--;
            int mx = 0, mxnum = -1, tot = 0, remain = 0;
            for (int j = 0; j < 10; j++) {
                if (nums[j] > mx)mx = nums[j], mxnum = j;
                tot += nums[j];
            }
            remain = tot - mx;
            if (mxnum != i)mx--;
            if (remain >= mx) {
                string ch = to_string(i);
                cout << ch;
                return i;
            }
            else {
                nums[i]++;
            }
        }
    }
    return 0;
}
int main() {
    io
        int t;
    cin >> t;
    while (t--) {
        sum = 0;
        for (int i = 0; i < 10; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
        int mx = 0, mxnum = -1, tot = 0, remain = 0;
        for (int i = 0; i < 10; i++) {
            if (nums[i] > mx)mx = nums[i], mxnum = i;
            tot += nums[i];
        }
        remain = tot - mx;
        if (mxnum != 0)mx--;
        if(tot==1){
            cout<<mxnum<<"\n";
            continue;
        }
        if(remain<mx){
            cout<<"-1\n";
            continue;
        }
        int step = 0;
        int cur = -1;
        while (step < sum) {
            cur = valid(cur, step);
            step++;
        }
        cout << "\n";
    }
}