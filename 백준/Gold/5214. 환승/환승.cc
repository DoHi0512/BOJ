#include <bits/stdc++.h>
using namespace std;
int dis[102001], vis[102001];
int main() {
	int n, k, m, temp;
	cin >> n >> k >> m;
	vector<vector<int>> arr(102001);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> temp;
			arr[temp].push_back(100001 + i);
			arr[100001 + i].push_back(temp);
		}
	}
	queue <int> que;
	que.push(1);
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (int x : arr[node]) {
			if (!dis[x]) dis[x] = dis[node] + 1;
			que.push(x);
		}
	}
	if (n == 1) cout << 1;
	else if (dis[n] == 0) printf("-1");
	else cout << dis[n] / 2 + 1;
}