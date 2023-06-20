#include <bits/stdc++.h>
using namespace std;
int weight[101], value[101], n, a, b, k, cache[100001][101];
int dp(int vol, int idx) {
	if (idx == n) return 0;
	int &ret = cache[vol][idx];
	if (ret != 0) return ret;
	ret = dp(vol, idx + 1);
	if (vol >= weight[idx]) ret = max(ret, dp(vol - weight[idx], idx + 1) + value[idx]);
	return ret;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d %d",&a,&b);
		weight[i] = a;
		value[i] = b;
	}
	cout << dp(k, 0);
}