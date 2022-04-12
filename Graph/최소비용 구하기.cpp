#include <bits/stdc++.h>
using namespace std;
int INF = 987654321;
int main() {
	int n, m, s, e, a, b, w;
	int dis[1001], vis[1001] = {};
	vector<vector<pair<int, int>>> arr(1001);
	priority_queue <pair<int, int>> que;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
	}
	cin >> s >> e;
	fill(dis, dis + 1001, INF);
	que.push({ 0,s });
	dis[s] = 0;
	while (!que.empty()) {
		int node = que.top().second;
		que.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto x : arr[node]) {
			int cost = x.second;
			int nxtNode = x.first;
			if (dis[nxtNode] > dis[node] + cost) {
				dis[nxtNode] = dis[node] + cost;
				que.push({ -dis[nxtNode], nxtNode });
			}
		}
	}
	cout << dis[e];
}
