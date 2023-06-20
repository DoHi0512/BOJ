#include <bits/stdc++.h>
using namespace std;
int vis[10001];
int cnt= 0;
vector<vector<int>> arr(10001);

void dfs(int x){
  if(vis[x]) return;
  cnt++;
  vis[x] = 1;
  for(int node : arr[x]){
    dfs(node);
  }
}

int main() {
  priority_queue<pair<int,int>> pq;
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a, b;
    cin>>a>>b;
    arr[b].push_back(a);
  }
  for(int  i=1;i<=n;i++){
    fill(vis,vis+n + 1, 0);
    cnt = 0;
    dfs(i);
    pq.push({cnt,-i});
  }
  int maxi = pq.top().first;
  while(!pq.empty()){
    if(maxi != pq.top().first) break;
    int idx = pq.top().second;
    printf("%d ",-idx);
    pq.pop();
  }
}