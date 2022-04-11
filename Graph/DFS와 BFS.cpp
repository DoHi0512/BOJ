#include <iostream>
#include <queue>
int graph[1001][1001];
int n;
int visited[1001];
int visited1[1001];
std::queue <int> que;
using namespace std;
void dfs(int c) {
	cout << c << " ";
	visited1[c]++;
	for (int i = 1; i <= n; i++) {
		if (graph[c][i] != 0 && visited1[i] == 0) {
			dfs(i);
		}
	}
}
int main() {
	int m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		graph[temp1][temp2]++;
		graph[temp2][temp1]++;
	}
	dfs(v);
	cout << endl;
	que.push(v);
	visited[v]++;
	while (!que.empty()) {
		printf("%d ", que.front());
		for (int i = 0; i <= n; i++) {
			if (graph[que.front()][i]!=0 && visited[i]==0) {
				que.push(i);
				visited[i]++;
			}
		}
		que.pop();
	}
}
