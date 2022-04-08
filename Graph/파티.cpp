#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;
int INF = 987654321;
vector < vector<pair<int, int>>> arr(1001); // node , weight
int dis[1001];
bool vis[1001];
int memo[1001];
void dijkstra(int start) {
	fill(dis, dis + 1001, INF);
	fill(vis, vis + 1001, 0);
	priority_queue <pair<int, int>> que; // weight , node
	dis[start] = 0;
	que.push({ 0,start });
	while (!que.empty()) {
		int node = que.top().second;
		que.pop();
        vis[node] = true;
		for (auto x : arr[node]) {
			int a = x.first;
			int b = x.second;
			if (!vis[a]) {
				if (dis[a] > dis[node] + b) {
					dis[a] = dis[node] + b;
					que.push({ -dis[a],a });
				}
			}
		}
	}
}
int main() {
	int n, m, a, b, w, x, maxi = -1;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		arr[a].push_back({ b,w });
	}
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			dijkstra(i);
			if(dis[x] != INF) memo[i] = dis[x];
		}
	}
	dijkstra(x);
	for (int i = 1; i <= n; i++) {
		if (dis[i] != INF) {
			if (maxi < dis[i] + memo[i]) maxi = dis[i] + memo[i];
		}
	}
	cout << maxi;

}
