#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define io                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define MAXN 2000005
//#define int long long
using namespace std;

signed main()
{
    io
        ll w,
        x, y, t, d;
    cin >> w >> x >> y >> t >> d;
    ll day = 0;
    d++;
    bool flag = 1;
    if (w <= t)
    {
        cout << "0\n";
    }
    else
    {
        while (d <= 7)
        {
            if (d == 1)
            {
                w += x;
            }
            else
            {
                w -= y;
            }
            day++;
            if (w <= t)
            {
                cout << day << "\n";
                flag = 0;
                break;
            }
            d++;
        }
        if (flag)
        {
            ll week = (6 * y) - x;
            ll r = (w - t) % week;
            day += (((w - t) / week) * 7);
            d = 1;
            while (r > 0)
            {
                if (d == 1)
                {
                    r += x;
                }
                else
                {
                    r -= y;
                }
                d++;
                day++;
            }
            cout << day << "\n";
        }
    }
}