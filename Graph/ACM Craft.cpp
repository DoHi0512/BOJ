#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int deg[32001] = {}, n, m, a, b, w, result[32001] = {}, value[32001] = {};
		cin >> n >> m;
		queue <int> que;
		vector < vector<int >> arr(32001);
		for (int i = 1; i <= n; i++) {
			cin >> value[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			deg[b]++;
		}
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (!deg[i]) que.push(i);
		}
		while (!que.empty()) {
			int node = que.front();
			for (int i : arr[node]) {
				deg[i]--;
				if (!deg[i]) que.push(i);
				result[i] = max(result[i], result[node] + value[node]);
			}
			que.pop();
		}
		printf("%d\n", value[w] + result[w]);
	}
}

