#include <bits/stdc++.h>
using namespace std;
int arr[65][65];
void divide(int n, int y, int x) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}
	bool flag = true;
	int color = arr[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (color != arr[i][j]) flag = false;
		}
	}
	if (flag) {
		cout << color;
	}
	else {
		printf("(");
		int d = n / 2;
		divide(d, y, x);
		divide(d, y, x + d);
		divide(d, y + d, x);
		divide(d, y + d, x + d);
		printf(")");
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			arr[i][j] = a[j] - 48;
		}
	}
	divide(n, 0, 0);
}
