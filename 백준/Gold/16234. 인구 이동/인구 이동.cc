#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[51][51];
bool vis[51][51];
int n,m,l,r,gap;
int total,cnt;
queue <pair<int,int>> que;
bool inRange(int y, int x){
  if(y == n || x == n || y < 0 || x < 0) return false;
  return true;
}
void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      vis[i][j] = 0;
    }
  }
}
void dfs(int y, int x){
  if(vis[y][x]) return;
  vis[y][x] = true;
  que.push({y,x});
  total += arr[y][x];
  cnt++;
  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(inRange(ny,nx) && abs(arr[y][x] - arr[ny][nx]) >= l && abs(arr[y][x] - arr[ny][nx]) <= r){
      dfs(ny,nx);
    }
  }
}
int main(){
  int ans = 0;
  cin>>n>>l>>r;
  gap = r-l;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  bool flag = true;
  while(flag){
    ans++;
    flag = false;
    reset();
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        if(!vis[i][j]){
          cnt = 0;
          total = 0;
          dfs(i,j);
          if(cnt > 1) flag = true;
          while(!que.empty()){
            // printf("%d [%d %d]\n",ans,i,j);
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            arr[y][x] = int(total/cnt);
          }
        }
    }
  }
  cout<<ans - 1;
}