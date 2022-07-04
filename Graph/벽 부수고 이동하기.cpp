#include <bits/stdc++.h>
using namespace std;
int n, m, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, arr[1001][1001], dis[1001][1001], vis[1001][1001][2], mini = 987654321;
bool inRange(int y, int x) {
	if (y == n || y < 0 || x == m || x < 0) return false;
	return true;
}
int main() {
	cin >> n >> m;
	queue < pair<pair<int, int>, int>> que; // y,x,chance
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	que.push({ {0,0},1 });
	while (!que.empty()) {
		int y = que.front().first.first;
		int x = que.front().first.second;
		int chance = que.front().second;
		que.pop();
		if (vis[y][x][chance]) continue;
		vis[y][x][chance] = 1;
		if (y == n - 1 && x == m - 1) {
			mini = min(dis[y][x], mini);
		}
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (inRange(ny, nx)) {
				if (arr[ny][nx] && chance) {
					dis[ny][nx] = dis[y][x] + 1;
					que.push({ {ny,nx},0 });
				}
				else if (!arr[ny][nx]) {
					dis[ny][nx] = dis[y][x] + 1;
					que.push({ {ny,nx},chance });
				}
			}
		}
	}
	if (mini == 987654321) cout << -1;
	else cout << mini + 1;
}
