#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, mini = 10010, ans = 0, ta, tb;
		int dis[10001] = {}, deg[10001] = {}, parent[10001] = {};
		bool vis[10001] = {};
		int root = 0;
		cin >> n;
		vector<vector<int>> arr(10001);
		queue <int> que;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			deg[b]++;
			parent[b] = a;
		}
		cin >> a >> b;
		ta = a;
		tb = b;
		for (int i = 1; i <= n; i++) {
			if (!deg[i]) root = i;
		}
		que.push(root);
		while (!que.empty()) {
			int node = que.front();
			que.pop();
			vis[node] = true;
			for (int x : arr[node]) {
				if (!vis[x]) {
					dis[x] = dis[node] + 1;
					que.push(x);
				}
			}
		}
		if (dis[a] > dis[b]) swap(a, b);
		while (dis[a] != dis[b]) b = parent[b];
		int flag = 1;
		
		while (a != b) {
			a = parent[a];
			b = parent[b];
			if (a == tb) {
				cout << tb << "\n";
				flag = 0;
				break;
			}
			if (b == ta) {
				cout << ta << "\n";
				flag = 0;
				break;
			}
		}
		if (flag) cout << a << "\n";
	}
}
