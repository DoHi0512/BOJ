#include <bits/stdc++.h>
using namespace std;
int lis[1000001];
int main() {
	int n, temp,idx = 1;
	cin >> n;
	cin >> temp;
	n--;
	lis[0] = temp;
	while (n--) {
		cin >> temp;
		if (temp > lis[idx - 1]) {
			lis[idx++] = temp;
		}
		else {
			lis[lower_bound(lis, lis + idx, temp) - lis] = temp;
		}
	}
	cout << idx;
}
