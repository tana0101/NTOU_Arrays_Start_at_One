#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main() {

	ll n, i, j, k, temp, sum = 0;
	vector<long long int> a, b, c, f, e, d, ans, ans2;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
		b.push_back(temp);
		c.push_back(temp);
		if (temp != 0)d.push_back(temp);
		e.push_back(temp);
		f.push_back(temp);
	}
	
	//前半枚舉
	for (i = 0; i < a.size(); i++) {
		for (j = 0; j < b.size(); j++) {
			for (k = 0; k < c.size(); k++) {
				//cout << a[i] * b[j] + c[k] << "\n";
				ans.push_back(a[i] * b[j] + c[k]);
			}
		}
	}
	//後半枚舉
	for (i = 0; i < f.size(); i++) {
		for (j = 0; j < e.size(); j++) {
			for (k = 0; k < d.size(); k++) {
				//cout << (f[i] + e[j])*d[k] << "\n";
				ans2.push_back((f[i] + e[j])*d[k]);
			}
		}
	}
	sort(ans2.begin(), ans2.end());
	//二分查找 (前半=後半)
	for (i = 0; i < ans.size(); i++) {
		sum += upper_bound(ans2.begin(), ans2.end(), ans[i]) - lower_bound(ans2.begin(), ans2.end(), ans[i]);
	}

	cout << sum << "\n";

	return 0;
}
