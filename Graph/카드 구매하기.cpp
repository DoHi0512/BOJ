#include <bits/stdc++.h>
using namespace std;
int N, arr[1001], memo[1001];
int dp(int n) {
	if (n == N) return 0;
	if (memo[n]) return memo[n];
	int maxi = -1;
	for (int i = 1; i <= N; i++) {
		if (n + i <= N) {
			maxi = max(maxi, dp(n + i) + arr[i]);
		}
	}
	return memo[n] = maxi;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cout << dp(0);
}
