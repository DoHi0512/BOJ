#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[101][101];
int dis[101][101];
int n, m;
bool inRange(int y, int x){
  if(y == m || x == n || y < 0 || x < 0) return false;
  return true;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    string temp;
    cin>>temp;
    for(int j=0;j<n;j++){
      dis[i][j] = 987654321;
      arr[i][j] = temp[j] - '0';
    }
  }
  queue <pair<int,pair<int,int>>> que;
  que.push({0,{0,0}});
  while(!que.empty()){
    auto data = que.front();
    int y = data.second.first;
    int x = data.second.second;
    int cnt = data.first;
    que.pop();
    if(cnt >= dis[y][x]) continue;
    dis[y][x] = cnt;
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(inRange(ny,nx)){
        if(arr[ny][nx] == 1){
          que.push({cnt + 1,{ny,nx}});
        }
        else que.push({cnt, {ny,nx}});
      }
    }
  }
  printf("%d",dis[m-1][n-1]);
}