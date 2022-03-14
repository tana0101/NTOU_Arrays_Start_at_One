#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, t, m, k, temp, i;
	vector<int> a, tmp;
	cin >> n >> k;

	for (i = 0; i < 10; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	
	ll N = pow(10, n);
	bool ans = false;
	for (int y = 0; y < N; y++) {
		ll x = k * y;
		if (x >= N) break;
		tmp = a;
		string str = to_string(x) + to_string(y);
		while (str.length() < 2 * n)str += "0";
		bool found = true;
		for (int i = 0; i < str.length(); i++) {
			tmp[str[i] - '0']--;
			if (tmp[str[i] - '0'] < 0) {
				found = false;
				break;
			}
		}
		if (found) {
			ans = true;
			cout << setw(n)<<setfill('0')<< x << " ";
			cout << setw(n)<<setfill('0')<< y << "\n";
		}
	}
	if (!ans)cout << "There are no solutions.\n";

	return 0;
}
