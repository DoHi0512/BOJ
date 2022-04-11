#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, a, b, kv[101] = {};
	cin >> n >> m;
	vector <vector<int>> arr(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		queue <int> que;
		que.push(i);
		int vis[101] = {}, dis[101] = {};
		dis[i] = 0;
		while (!que.empty()) {
			int node = que.front();
			que.pop();
			if (vis[node]) continue;
			vis[node] = true;
			for (int x : arr[node]) {
				if (dis[x] == 0) dis[x] = dis[node] + 1;
				else dis[x] = min(dis[node] + 1, dis[x]);
				que.push(x);
			}
		}
		for (int j = 1; j <= n; j++) {
			kv[i] += dis[j];
		}
		
	}
	pair<int, int> mi = { 999999,999999 };
	for (int i = 1; i <= n; i++) {
		if (kv[i] < mi.first) mi = { kv[i],i };
		else if (kv[i] == mi.first && i < mi.second) mi = { kv[i],i };
	}
	cout << mi.second;

}
