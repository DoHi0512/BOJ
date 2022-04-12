#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, k, a, b, w, node;
	cin >> n >> m >> k;
	vector < vector < pair<int, int> >> arr(n + 1); //node,weight
	vector <int> dis(n + 1);
	vector <bool> vis(n + 1);
	priority_queue <pair<int, int>> que; // weight,node
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		arr[a].push_back({ b,w });
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = 98765432;
	}
	dis[k] = 0;
	que.push({ 0, k });
	while (!que.empty()) {
		node = que.top().second;
		que.pop();
		vis[node] = true;
		for (auto x : arr[node]) {
			a = x.first;
			b = x.second;
			if (!vis[a]) {
                if(dis[a] > dis[node] + b) {
                    dis[a] = dis[node] + b;
				que.push({ -dis[a] ,a });
                }
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 98765432) printf("INF\n");
		else printf("%d\n", dis[i]);
	}
}
