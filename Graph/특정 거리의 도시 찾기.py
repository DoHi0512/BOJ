from collections import deque
n, m, k, s = map(int, input().split())
arr = [[0] for _ in range(n + 1)]
dis = [987654321] * (n + 1)
vis = [False] * (n + 1)

que = deque()

for i in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)

que.append(s)
dis[s] = 0
while (que):
    node = que.popleft()
    if vis[node] : continue
    vis[node] = True
    for i in arr[node]:
        if dis[i] > dis[node] + 1 : dis[i] = dis[node] + 1
        que.append(i)

if k not in dis:
    print(-1)
    exit(0)

ans = []
for i in range(1, n + 1):
    if dis[i] == k : ans.append(i)

ans.sort()

for i in ans:
    print(i)
