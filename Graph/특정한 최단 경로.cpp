#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int INF = 987654321;
vector < vector<pair<int, int>>> arr(801); // node , weight
int dis[801];
bool vis[801];
void dijkstra(int start) {
	fill(dis, dis + 801, INF);
	fill(vis, vis + 801, 0);
	priority_queue <pair<int, int>> que; // weight , node
	dis[start] = 0;
	que.push({ 0,start });
	while (!que.empty()) {
		int node = que.top().second;
		int cost = que.top().first;
		que.pop();
		for (auto x : arr[node]) {
			int a = x.first;
			int b = x.second;
			if (!vis[a]) {
				if (dis[a] > dis[node] + b) {
					dis[a] = dis[node] + b;
					que.push({ -b,a });
				}
			}
		}
	}
}
int main() {
	int n, m, a, b, w;
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		arr[a].push_back({ b,w });
		arr[b].push_back({ a,w });
	}
	cin >> a >> b;
	dijkstra(a);
	int a1 = dis[1];
	int ab = dis[b];
	int an = dis[n];

	dijkstra(b);
	int b1 = dis[1];
	int bn = dis[n];
	if (a1 == INF || ab == INF || an == INF || b1 == INF || bn == INF) printf("-1");
	else cout << min(a1 + ab + bn, b1 + ab + an);
}
