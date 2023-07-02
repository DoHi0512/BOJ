#include <bits/stdc++.h>
using namespace std;
int lis[1000001], idx1[1000001], arr[1000001];
int main() {
	stack <int> stk;
	int n, temp, idx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		arr[i] = temp;
		if (idx == 0) {
			lis[idx++] = temp; 
			idx1[i] = 0;
		}
		if (temp > lis[idx - 1]) {
			idx1[i] = idx;
			lis[idx++] = temp;
		}
		else {
			idx1[i] = lower_bound(lis, lis + idx, temp) - lis;
			lis[lower_bound(lis, lis + idx, temp) - lis] = temp;
		}
	}
	cout << idx << endl;
	for (int i = n; i >= 1; i--) {
		if (idx == idx1[i] + 1) {
			stk.push(arr[i]);
			idx--;
		}
	}
	while (!stk.empty()) {
		printf("%d ", stk.top());
		stk.pop();
	}
}