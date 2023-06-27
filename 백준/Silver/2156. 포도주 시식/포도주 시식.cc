#include <bits/stdc++.h>
using namespace std;
int arr[10001], value[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	value[1] = arr[1];
	value[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		value[i] = max(arr[i - 1] + value[i - 3], value[i - 2]) + arr[i];
		value[i] = max(value[i - 1], value[i]);
	}
	cout << value[n];
}