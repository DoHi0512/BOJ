#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int vis[1501][1501];
int n, m, arr[1510][1510], day[1510][1510], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, mini = MAX, maxi = -1;
class pos {
public:
	int x, y, dis;
	pos(int y, int x, int dis) : y(y), x(x), dis(dis) {};
};
pos target(0, 0, 0);
pos a(0, 0, 0);
void ps(int start, int end) {
	memset(vis, 0, sizeof(vis));
	if (start > end) return;
	int mid = (start + end) / 2;
	queue <pos> que;
	bool flag = 0;
	que.push(a);
	while (!que.empty()) {
		pos data(que.front());
		int x = data.x;
		int y = data.y;
		que.pop();
		if (x == target.x && y == target.y) {
			flag = 1;
			break;
		}
		if (vis[y][x]) continue;
		vis[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (day[ny][nx] != MAX && day[ny][nx] <= mid) {
				que.push(pos(ny, nx, 0));
			}
		}
	}
	if (flag) {
		mini = mid;
		ps(start, mid - 1);
	}
	else {
		ps(mid + 1, end);
	}
}
int main() {
	queue<pos> bird, water;
	bool flag = true;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) day[i][j] = MAX;
	}
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == '.') {
				water.push(pos(i, j, 0));
			}
			else if (temp[j - 1] == 'L') {
				water.push(pos(i, j, 0));
				if (flag) {
					a.x = j;
					a.y = i;
					flag = false;
				}
				else {
					target.y = i;
					target.x = j;
				}
			}
			else {
				arr[i][j] = -1;
			}
		}
	}
	while (!water.empty()) {
		pos data(water.front());
		water.pop();
		int x = data.x;
		int y = data.y;
		int dis = data.dis;
		if (day[y][x] != MAX) continue;
		day[y][x] = dis;
		maxi = max(maxi, dis);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[ny][nx] == -1) {
				water.push(pos(ny, nx, dis + 1));
			}
		}
	}
	ps(0, maxi);
	cout << mini;
}
