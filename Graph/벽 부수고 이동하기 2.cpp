#include <bits/stdc++.h>
using namespace std;
int n, m, k, arr[1001][1001], dis[1001][1001], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, ans = 987654321;
bool vis[1001][1001][11];
class pos {
public:
	int x, y, chance;
	pos(int y, int x, int chance) : y(y), x(x), chance(chance) {};
};
bool inRange(int y, int x) {
	if (y == n || x == m || y < 0 || x < 0) return false;
	return true;
}
int main() {
	queue <pos> que;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	que.push(pos(0, 0, k));
	while (!que.empty()) {
		pos data(que.front());
		int y = data.y;
		int x = data.x;
		int chance = data.chance;
		que.pop();
		if (y == n - 1 && x == m - 1) {
			ans = min(ans, dis[y][x]);
			continue;
		}
		if (vis[y][x][chance]) continue;
		vis[y][x][chance] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inRange(ny, nx)) {
				if (arr[ny][nx] && chance) {
					dis[ny][nx] = dis[y][x] + 1;
					que.push(pos(ny, nx, chance - 1));
				}
				else if (!arr[ny][nx]) {
					dis[ny][nx] = dis[y][x] + 1;
					que.push(pos(ny, nx, chance));
				}
			}
		}
	}
	cout << (ans == 987654321 ? -1 : ans + 1);
}
