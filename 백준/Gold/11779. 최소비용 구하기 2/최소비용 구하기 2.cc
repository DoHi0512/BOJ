#include <bits/stdc++.h>
using namespace std;
int INF = 987654321;
int dis[1001], vis[1001], path[1001];
vector<vector<pair<int, int>>> arr(1001);
stack<int> stk;
void dijkstra(int start, int end) {
	priority_queue <pair<int, int>> que;
	fill(dis, dis + 1001, INF);
	fill(vis, vis + 1001, 0);
	dis[start] = 0;
	que.push({ 0,start });
	while (!que.empty()) {
		int node = que.top().second;
		if (node == end) break;
		vis[node] = true;
		que.pop();
		for (auto x : arr[node]) {
			int nxtNode = x.first;
			int cost = x.second;
			if (!vis[nxtNode]) {
				if (dis[nxtNode] > dis[node] + cost) {
					path[nxtNode] = node;
					dis[nxtNode] = dis[node] + cost;
					que.push({ -dis[nxtNode],nxtNode });
				}
			}
		}
	}
}
void btPath(int curNode) {
	if (curNode == 0) return;
	stk.push(curNode);
	btPath(path[curNode]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b, w, m, s, e;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
	}
	cin >> s >> e;
	dijkstra(s, e);
	cout << dis[e] << "\n";
	btPath(e);
	cout << stk.size() << "\n";
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
}