#include <bits/stdc++.h>
using namespace std;
int size1[201], link[201], route[1001];
int finding(int x) {
	if (link[x] == x) return x;
	return link[x] = finding(link[x]);
}
void unite(int a, int b) {
	a = finding(a);
	b = finding(b);
	if (size1[a] < size1[b]) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	link[b] = a;
	size1[a] += size1[b];
}
bool same(int a, int b) {
	return finding(a) == finding(b);
}
int main() {
	int n, m, temp, pre;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		size1[i] = 1;
		link[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp && !same(i, j)) {
				unite(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> route[i];
	}
	for (int i = 0; i < m - 1; i++) {
		if (!same(route[i], route[i + 1])) {
			printf("NO");
			return 0;
		}
	}
	cout << "YES";
}
