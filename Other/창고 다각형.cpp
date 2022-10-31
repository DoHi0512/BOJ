#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, arr[1001] = { 0 }, l, h, sum = 0, max_hei = -1;;
	stack <pair<int, int>> stk;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		arr[l] = h;
	}
	stk.push({ 0,0 });
	for (int i = 0; i < 1001; i++) {
		if (stk.top().first < arr[i]) {
			sum += (i - stk.top().second) * stk.top().first;
			stk.pop();
			stk.push({ arr[i],i });
		}
	}
	int dis;
	for (int i = stk.top().second; i < 1001; i++) {
		if (arr[i] == stk.top().first) {
			dis = i - stk.top().second;
		}
	}
	sum += (dis + 1) * stk.top().first;
	stk.pop();
	stk.push({ 0,0 });
	for (int i = 1000; i >= 0; i--) {
		if (stk.top().first < arr[i]) {
			sum += (stk.top().second - i) * stk.top().first;
			stk.pop();
			stk.push({ arr[i],i });
		}
	}
	cout << sum;
}
