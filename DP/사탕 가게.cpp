#include <bits/stdc++.h>
#define INF 1e9*1e5
using namespace std;
int cal[5001], n, cost[5001], budget, memo[10001];
double temp;
int dp(int total) {
	if (memo[total]) return memo[total];
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (total + cost[i] <= budget) {
			maxi = max(maxi, dp(cost[i] + total) + cal[i]);
		}
	}
	return memo[total] = maxi;
}
int main() {
	cin >> n;
	cin >> temp;
	while (!(n == 0 && temp == 0)) {
		budget = (temp * 100 + 0.5);
		for (int i = 0; i < n; i++) {
			cin >> cal[i];
			cin >> temp;
			cost[i] = (temp * 100 + 0.5);
		}
		cout << dp(0) << "\n";
		cin >> n;
		cin >> temp;
		fill(memo, memo + 10001, 0);
	}
}
