#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m,arr[501][501], dp[501][501];
bool inRange(int y,int x){
  if(y == n + 1 || x == m + 1 || x == 0 || y == 0) return false;
  return true;
}
int dfs(int y,int x) {
  if(y == n && x == m){
    return true;
  }
  if(dp[y][x] != -1) return dp[y][x];
  dp[y][x] = 0;
  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(inRange(ny,nx) && arr[ny][nx] < arr[y][x]){
      dp[y][x] = dfs(ny,nx) + dp[y][x];
    }
  }
  return dp[y][x];
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&arr[i][j]);
      dp[i][j] = -1;
    }
  }
  cout<<dfs(1,1);
}