#include <bits/stdc++.h>
using namespace std;
using ull = long long int;
int main() {
	ull n, T, temp;
	cin >> T;
	while (T--) {
		ull total = 0;
		priority_queue<ull> que;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			que.push(-temp);
		}
		while (que.size() != 1){
			ull a = -que.top();
			que.pop();
			ull b = -que.top();
			que.pop();
			total += a + b;
			que.push(-(a + b));
		}
		printf("%lld\n", total);
	}
}
