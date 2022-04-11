#include <bits/stdc++.h>
using namespace std;
int dis[200001];
bool vis[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	queue <int> que;
	que.push(n);
	dis[n] = 0;
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		if (node == k) break;
		if (vis[node]) continue;
		vis[node] = true;
		if (node - 1 >= 0) {
			if (dis[node - 1]) dis[node - 1] = min(dis[node - 1], dis[node] + 1);
			else dis[node - 1] = dis[node] + 1;
			que.push(node - 1);
		}
		if (node + 1 <= 200000) {
			if (dis[node + 1]) dis[node + 1] = min(dis[node + 1], dis[node] + 1);
			else dis[node + 1] = dis[node] + 1;
			que.push(node + 1);
		}
		if (node * 2 <= 200000) {
			if (dis[node * 2]) dis[node * 2] = min(dis[node * 2], dis[node] + 1);
			else dis[node * 2] = dis[node] + 1;
			que.push(node * 2);
		}
	}
	cout << dis[k];
}
