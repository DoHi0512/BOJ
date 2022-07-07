#include <bits/stdc++.h>
using namespace std;
int arr[51][51], n, m, maxi = -1, temp[51][51], dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
bool inRange(int y, int x) {
	if (y == n || y < 0 || x == m || x < 0) return false;
	return true;
}
class location {
public:
	int x, y, col, dis;
	location(int y, int x, int col, int dis) : y(y), x(x), col(col), dis(dis) {};
};
int bfs() {
	queue <location> que;
	int flower = 0;
	int vis[51][51] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = arr[i][j];
			if (temp[i][j] == 3 || temp[i][j] == 4) {
				que.push(location(i, j, temp[i][j], 0));
			}
		}
	}
	while (!que.empty()) {
		location data(que.front());
		int x = data.x;
		int y = data.y;
		int col = data.col;
		int dis = data.dis;
		que.pop();
		if (temp[y][x] == -1) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inRange(ny, nx)) {
				if (temp[ny][nx] != 0 && temp[ny][nx] != -1) {
					if (temp[ny][nx] != col && vis[ny][nx] == dis + 1) {
						temp[ny][nx] = -1;
						flower++;
					}
					else if (temp[ny][nx] == 1 || temp[ny][nx] == 2) {
						temp[ny][nx] = col;
						vis[ny][nx] = dis + 1;
						que.push(location(ny, nx, col, dis + 1));
					}
				}
			}
		}
	}
	return flower;
}
void bt(int a, int g, int r) {
	if (a == n * m + 1) return;
	if (g == 0 && r == 0) {
		int result = bfs();
		maxi = max(result, maxi);
		return;
	}
	int y = a / m;
	int x = a % m;
	if (arr[y][x] == 2 && g != 0) {
		arr[y][x] = 3;
		bt(a + 1, g - 1, r);
		arr[y][x] = 2;
	}
	if (arr[y][x] == 2 && r != 0) {
		arr[y][x] = 4;
		bt(a + 1, g, r - 1);
		arr[y][x] = 2;
	}
	bt(a + 1, g, r);
	
}
int main() {
	int r, g;
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	queue <location> a;
	bt(0, g, r);
	cout << maxi;
}
