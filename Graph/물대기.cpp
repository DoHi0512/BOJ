#include <bits/stdc++.h>
using namespace std;
int link[301], len[301];
int find(int x) {
	if (link[x] == x) return x;
	return link[x] = find(link[x]);
}
bool same(int a, int b) {
	return find(a) == find(b);
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (len[a] < len[b]) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	link[b] = link[a];
	len[a] += len[b];
}
int main() {
	int n, a, b, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		link[i] = i;
		len[i] = 1;
	}
	priority_queue <pair<int, pair<int, int>>> que; // value a->b
	int newNode = n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		que.push({ -a,{i,newNode} });
		que.push({ -a,{newNode,i} });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (a != 0) {
				que.push({ -a,{j,i} });
				que.push({ -a,{i,j} });
			}
		}
	}
	while (!que.empty()) {
		pair<int, pair<int, int>> node = que.top();
		int depart = node.second.first;
		int arrive = node.second.second;
		int weight = -node.first;
		if (!same(depart, arrive)) {
			sum += weight;
			unite(depart, arrive);
		}
		que.pop();
	}
	cout << sum;
}

