#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	ll n, k;
	//pair<int, int> cost[2005][2005];
	vector< vector <pair<int, int> > > cost;
	//vector<vector<int>> dp(2005,vector<int>(2005));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vector <pair<int, int> >p;
		for (int j = 0, cst; j < k; j++) {
			cin >> cst;
			p.push_back({ cst,j });
		}
		cost.push_back(p);
		sort(cost[i].begin(), cost[i].end(), cmp);
	}
	int sum1 = cost[0][0].first, sum2 = cost[0][1].first;
	for (int i = 1,prei=cost[0][0].second; i < n; i++) {
		if (cost[i][0].second==prei) {
			sum1 += cost[i][1].first;
			prei = cost[i][1].second;
		}
		else {
			sum1 += cost[i][0].first;
			prei = cost[i][0].second;
		}
	}
	for (int i = 1,prei = cost[0][1].second; i < n; i++) {
		if (cost[i][0].second == prei) {
			sum2 += cost[i][1].first;
			prei = cost[i][1].second;
		}
		else {
			sum2 += cost[i][0].first;
			prei = cost[i][0].second;
		}
	}
	cout << min(sum1, sum2) << "\n";
	return 0;
}
