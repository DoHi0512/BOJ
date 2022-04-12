#include <bits/stdc++.h>
using namespace std;
int main() {
	int test, v, e, a, b, node, flag;
	cin >> test;
	for (int t = 0; t < test; t++) {
		scanf("%d %d", &v, &e);
		flag = 1;
		vector<vector<int>> arr(v + 1);
		vector <int> color(v + 1);
		vector <bool> vis(v + 1);
		queue <int> que;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for (int i = 1; i <= v && flag; i++) {
			que.push(i);
			color[i] = 1;
			while (!que.empty()) {
				node = que.front();
				que.pop();
				if (vis[node]) continue;
				vis[node] = true;
				for (int num : arr[node]) {
					if (!color[num]) color[num] = color[node] % 2 + 1;
					else if (color[num] == color[node]) {
						flag = 0;
						break;
					}
					que.push(num);
				}
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}


