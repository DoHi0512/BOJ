#include <bits/stdc++.h>
#define INF 10987654321
#define MAX 1000001
#define lli long long int
using namespace std;
lli n, m, s, a, b, w, e, ans, money;
vector<vector<pair<lli, lli>>> arr(MAX);
lli dis[MAX], dp[MAX];
priority_queue<pair<lli, lli>> que;
void dijkstra() {
    while (!que.empty()) {
        lli node = que.top().second;
        lli dist = -que.top().first;
        que.pop();
        if (dist > dis[node]) continue;
        for (auto x : arr[node]) {
            lli nxt = x.first;
            lli cost = x.second;
            if (dis[node] + cost <= money) {
                if (dp[nxt]) {
                    dp[nxt] = min(dp[nxt], max(dp[node], cost));
                }
                else {
                    dp[nxt] = max(dp[node], cost);
                }
            }
;           if (dis[nxt] > dis[node] + cost && dis[node] + cost <= money) {
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
    cin >> n >> m >> s >> e >> money;
    que.push({ 0,s });
    dis[s] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        arr[a].push_back({ b,w });
        arr[b].push_back({ a,w });
    }
    dijkstra();
    cout << (dp[e] ? dp[e] : -1);
}

