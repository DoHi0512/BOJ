#include <bits/stdc++.h>
using namespace std;
using ull = long long int;
ull link[100001], dia[100001], sum;
ull find(ull x) {
	if (x == link[x]) return x;
	return find(link[x]);
}
void unite(ull a, ull b) {
	a = find(a);
	b = find(b);
	if (dia[a] < dia[b]) swap(a, b);
	dia[a] += dia[b];
	link[b] = a;
}
int main() {
	ull v, e, a, b, c;
	cin >> v >> e;
	priority_queue<pair<ull, pair<ull, ull >>> que;
	for (int i = 1; i <= v; i++) {
		dia[i] = 1;
		link[i] = i;
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		que.push({ -c,{a,b} });
	}
	while (!que.empty()) {
		pair < ull, pair <ull, ull>> node = que.top();
		if (find(node.second.first) != find(node.second.second)) {
			sum += -node.first;
			unite(node.second.second, node.second.first);
		}
		que.pop();
	}
	cout << sum;
}

