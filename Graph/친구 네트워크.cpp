#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int INF = 987654321;
int link[1000001], size1[1000001];
int finding(int x) {
	if (x == link[x]) return x;
	return link[x] = finding(link[x]);
}
bool same(int a, int b) {
	return finding(a) == finding(b);
}
void unite(int a, int b) {
	a = finding(a);
	b = finding(b);
	//if (size1[a] < size1[b]) swap(a, b);
	size1[a] += size1[b];
	//size1[b] = size1[a];
	link[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, idx = 0, val1, val2;
		cin >> n;
		for (int i = 0; i <= n * 2; i++) {
			size1[i] = 1;
			link[i] = i;
		}
		string a, b;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (m.find(a) == m.end()) {
				m.insert({ a,idx++ });
			}
			cin >> b;
			if (m.find(b) == m.end()) {
				m.insert({ b,idx++ });
			}
			val1 = m[a];
			val2 = m[b];
			if (!same(val1, val2)) {
				unite(val1, val2);
			}
			cout << size1[finding(val1)] << "\n";
		}
	}
}
