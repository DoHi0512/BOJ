#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> arr[100001];
int MaxDisNode;
int MaxDis;
void dfs(int node, vector <bool> vis, int dis) {
	if (vis[node]) return;
	if (dis > MaxDis) {
		MaxDis = dis;
		MaxDisNode = node;
	}
	vis[node] = true;
	for (auto num : arr[node]) {
		dfs(num.first, vis, dis + num.second);
	}
}
int main() {
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			arr[a].push_back({ b,c });
		}
	}
	vector <bool> vis(100001);
	vis.assign(n + 1, 0);
	dfs(1, vis, 0);
	MaxDis = 0;
	dfs(MaxDisNode, vis, 0);
	printf("%d", MaxDis);
}
