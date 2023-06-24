#include <bits/stdc++.h>
#define INF 10987654321
#define MAX 1000001
#define lli long long int
using namespace std;
lli n, m, s, a, b, w, k, ans;
vector<vector<pair<lli, lli>>> arr(MAX);
lli dis[MAX];
lli maxi = -INF;
priority_queue<pair<lli, lli>> que;
void dikstra() {
    while (!que.empty()) {
        lli dist = -que.top().first;
        lli node = que.top().second;
        que.pop();
        if (dist > dis[node]) continue;
        for (auto x : arr[node]) {
            lli nxt = x.first;
            lli cost = x.second;
            if (dis[nxt] > dis[node] + cost) {
                dis[nxt] = dis[node] + cost;
                que.push({ -dis[nxt],nxt });
            }
        }
    }
}	
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dis, dis + MAX, INF);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        arr[b].push_back({ a,w });
    }
    for (int i = 0; i < k; i++) {
        cin >> s;
        que.push({ 0,s });
        dis[s] = 0;
    }
    dikstra();
    for (int i = 1; i <= n; i++) {
        if (maxi < dis[i] && dis[i] != INF) {
            ans = i;
            maxi = dis[i];
        }
    }
    cout << ans << '\n' << maxi;
}