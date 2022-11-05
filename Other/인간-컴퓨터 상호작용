#include <bits/stdc++.h>
#define INF 1e9*1e5
using namespace std;
using ull = unsigned long long;
using ll = long long;
int arr[200001][26], n, a, b;
char c;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	cin >> n;
	for (int i = 0; i < str.size(); i++) {
		if(i) copy(arr[i - 1], arr[i - 1] + 26, arr[i]);
		arr[i][str[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		cin >> a >> b;
		if (a == 0)cout << arr[b][c - 'a'] << "\n";
		else cout << arr[b][c - 'a'] - arr[a - 1][c - 'a'] << "\n";
	}
}
