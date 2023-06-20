#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr(10001), SCC;
int num[10001], finish[10001], idx;
stack <int> stk;
int dfs(int node) {
	num[node] = ++idx;
	stk.push(node);
	int p = num[node];
	for (int x : arr[node]) {
		if (num[x] == 0) p = min(p, dfs(x));
		else if (!finish[x]) p = min(p, num[x]);
	}
	if (p == num[node]) {
		vector <int> scc;
		while(1) {
			int t = stk.top();
			stk.pop();
			scc.push_back(t);
			finish[t] = true;
			if (t == node) break;
		}
		SCC.push_back(scc);
	}
	return p;

}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!num[i]) dfs(i);
	}
	printf("%d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end());
	for (vector<int> x : SCC) {
		for (int y : x) {
			printf("%d ", y);
		}
		printf("-1\n");
	}
}

