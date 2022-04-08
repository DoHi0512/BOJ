#include <iostream>
#include <algorithm>
using namespace std;
int arr[51][51] = { 0, };
void dfs(int i,int j) {
	arr[i][j] = 0;
	if (arr[i - 1][j] == 1) {
		dfs(i - 1, j);
	}
	if (arr[i + 1][j] == 1) {
		dfs(i + 1, j);
	}
	if (arr[i][j - 1] == 1) {
		dfs(i, j - 1);
	}
	if (arr[i][j + 1] == 1) {
		dfs(i, j + 1);
	}
}

int main() {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int total = 0;
		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x]++;

		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					dfs(i,j);
					total++;
				}
			}
		}
		cout << total << endl;
	}


}
