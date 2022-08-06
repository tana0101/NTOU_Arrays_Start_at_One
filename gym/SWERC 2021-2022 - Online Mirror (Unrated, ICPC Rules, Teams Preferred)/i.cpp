#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define int long long
using namespace std;

struct point {
    point() {}
    point(ll _people, ll _loc) {
        people = _people;
        loc = _loc;
    }
    ll people;
    ll loc;
    friend bool operator<(point& a, point& b) {
        if (a.loc == b.loc) {
            a.people = -1, b.people = -1;
            return 1;
        }
        return a.loc < b.loc;
    }
};
signed main() {
    io
        int m, n;
        ll num;
    cin >> m >> n;
    vector<ll>disc;
    vector<point>house;
    for (int i = 0; i < m; i++) {
        cin >> num;
        house.push_back(point(num, i * 100));
        disc.push_back(i * 100);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        house.push_back(point(-1, num));
        disc.push_back(num);
    }
    sort(disc.begin(), disc.end());
    ll tot = unique(disc.begin(), disc.end()) - disc.begin();
    for (int i = 0; i < m+n; i++) {
        house[i].loc = lower_bound(disc.begin(), disc.begin() + tot, house[i].loc) - disc.begin();
    }
    sort(house.begin(), house.end());
    vector<ll>presum(tot + 1, 0), sufsum(tot + 1, 0);
    for (int i = 0; i < house.size(); i++) {
        if (i == 0) {
            if (house[i].people == -1)
                presum[i] = 0;
            else
                presum[i] = house[i].people;
        }
        else {
            if (house[i].people == -1)
                presum[i] = 0;
            else
                presum[i] = presum[i-1] + house[i].people;
        }
    }
    for (int i = house.size() - 1; i >= 0; i--) {
        if (i == house.size() - 1) {
            if (house[i].people == -1)
                sufsum[i] = 0;
            else
                sufsum[i] = house[i].people;
        }
        else {
            if (house[i].people == -1)
                sufsum[i] = 0;
            else
                sufsum[i] = sufsum[i+1] + house[i].people;
        }
    }
    ll ans = 0;
    for (int i = 0; i < tot - 1; i++) {
        ans = max(ans, presum[i] + sufsum[i + 1]);
    }
    cout << ans << "\n";
}