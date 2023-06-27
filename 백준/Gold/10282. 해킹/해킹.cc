#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m,d,c;
int mini = 98754321;

int cnt;
vector<vector<int>> arr(51);
int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n>>d>>c;
    int dis[10001];
    fill(dis,dis+10001,MAX);
    vector<vector<pair<int,int>>> arr(10001);
    for(int i=0;i<d;i++){
      int a, b, w;
      cin>>a>>b>>w;
      arr[b].push_back({a,w});
    }
    priority_queue <pair<int,int>> que;
    que.push({0,c});
    dis[c] = 0;
    while(!que.empty()){
      int node = que.top().second;
      int dist = -que.top().first;
      que.pop();
      if(dist > dis[node]) continue;
      for(auto x : arr[node]){
        int nxt = x.first;
        int cost = x.second;
        if(dis[nxt] > dis[node] + cost){
          dis[nxt] = dis[node] + cost;
          que.push({-dis[nxt],nxt});
        }
      }
    }
    int maxi = -1;
    int cnt = 0;
    for(int i=1;i<=n;i++){
      if(dis[i] != MAX) cnt++;
      if(maxi < dis[i] && dis[i] != MAX) maxi = dis[i];
    }
    printf("%d %d\n",cnt,maxi);
  }
}