#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, n, m, arr[1010][1010], dis[1010][1010], vis[1010][1010];
bool inRange(int y, int x) {
	if (y == n + 2 || y < 0 || x == m + 2 || x < 0) return false;
	return true;
}
int main() {
	char temp;
	cin >> n >> m;
	queue <pair<int, int>> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			if (temp == '#') {
				arr[i][j] = -1;
			}
			else if (temp == 'J') {
				arr[i][j] = 2;
				que.push({ i,j });
			}
			else if (temp == 'F') {
				arr[i][j] = 3;
				que.push({ i,j });
			}
			else arr[i][j] = 1;
		}
	}
	
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		if (vis[y][x]) continue;
		vis[y][x] = true;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (inRange(ny, nx)) {
				if (arr[y][x] == 2) {
					if (arr[ny][nx] == 0) {
						cout << dis[y][x] + 1;
						exit(0);
					}
					else if (arr[ny][nx] == 1) {
						dis[ny][nx] = dis[y][x] + 1;
						arr[ny][nx] = 2;
						que.push({ ny,nx });
					}
				}
				else if (arr[y][x] == 3) {
					if (arr[ny][nx] == 1 || arr[ny][nx] == 2) {
						arr[ny][nx] = 3;
						que.push({ ny, nx });
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
}
