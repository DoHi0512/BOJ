#include <bits/stdc++.h>
using namespace std;
int INF = 987654321;
int dis[10001], vis[10001];
vector<vector<pair<int, int>>> arr(10001);
void dijkstra(int start) {
	priority_queue <pair<int, int>> que;
	fill(dis, dis + 10001, INF);
	fill(vis, vis + 10001, 0);
	dis[start] = 0;
	que.push({ 0,start });
	while (!que.empty()) {
		int node = que.top().second;
		vis[node] = true;
		que.pop();
		for (auto x : arr[node]) {
			int nxtNode = x.first;
			int cost = x.second;
			if (!vis[nxtNode]) {
				if (dis[nxtNode] > dis[node] + cost) {
					dis[nxtNode] = dis[node] + cost;
					que.push({ -dis[nxtNode],nxtNode });
				}
			}
		}
	}
}
int main() {
	int n, a, b, w, maxi = -1, idx;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
		arr[b].push_back({ a,w });
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		if (maxi < dis[i]) {
			maxi = dis[i];
			idx = i;
		}
	}
	maxi = -1;
	dijkstra(idx);
	for (int i = 1; i <= n; i++) {
		if (dis[i] > maxi) maxi = dis[i];
	}
	cout << maxi;
}
