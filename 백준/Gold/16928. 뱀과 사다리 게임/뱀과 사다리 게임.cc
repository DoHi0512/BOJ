#include <bits/stdc++.h>
using namespace std;
int arr[101], vis[101], dis[101];
int main() {
	int n, m, a, b;
	queue <int> que;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	que.push(1);
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		if (node == 100) {
			cout << dis[100];
			exit(0);
		}
		vis[node] = 1;
		if (arr[node]) {
			if (!vis[arr[node]]) {
				que.push(arr[node]);
				if (dis[arr[node]] == 0) dis[arr[node]] = dis[node];
				else dis[arr[node]] = min(dis[node], dis[arr[node]]);
			}
		}
		else {
			for (int i = 1; i <= 6; i++) {
				if (!vis[node + i]) {
					que.push(node + i);
					if (dis[node + i] == 0) dis[node + i] = dis[node] + 1;
					else dis[node + i] = min(dis[node + i], dis[node] + 1);
				}
			}
		}
	}

}