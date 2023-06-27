#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[101][101];
int vis[101][101];
int n, m;
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a, b;
    cin>>a>>b;
    arr[a][b] = 1;
  }
  for(int i=1;i<=n;i++){
    arr[i][i] = 1;
  }
  for(int k = 1;k<=n;k++){
    for(int i = 1; i<=n;i++){
      for(int j= 1;j<=n;j++){
        if(arr[i][k] && arr[k][j]){
          vis[i][j] = 1;
          arr[i][j] = 1;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    int cnt = 0;
    for(int j=1;j<=n;j++){
      if(vis[i][j] || vis[j][i]) cnt++;
    }
    cout<< n-cnt<<'\n';
  }
}