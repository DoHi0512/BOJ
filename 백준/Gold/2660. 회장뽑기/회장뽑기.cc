#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dis[51][51];
int n, m,a,b;
int mini = 98754321;
int score[51];
int cnt;
vector<vector<int>> arr(51);
int main(){
  cin>>n;
  while(true){
    cin>>a>>b;
    if(a == -1 && b == -1) break;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for(int node=1; node <= n; node++){
    int vis[51] = {};
    int dis[51] = {};
    fill(dis,dis+51,987654321);
    queue <int> que;
    que.push(node);
    dis[node] = 0;
    while(!que.empty()){
      int v = que.front();
      que.pop();
      if(vis[v]) continue;
      vis[v] = 1;
      for(int x : arr[v]){
        if(dis[v] + 1 < dis[x]){
          que.push(x);
          dis[x] = dis[v] + 1;
        }
      }
    }
    int maxi = -1;
    for(int  i=1;i<=n;i++){
      maxi = max(maxi, dis[i]);
    }
    score[node] = maxi;
    mini = min(maxi,mini);
  }
  for(int i=1;i<=n;i++){
    if(score[i] == mini) cnt++;
  }
  printf("%d %d\n",mini,cnt);
  for(int i=1;i<=n;i++){
    if(score[i] == mini) printf("%d ",i);
  }
}