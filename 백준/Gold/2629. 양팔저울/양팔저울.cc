#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m, arr[31];
int memo[31][40001];
void dp(int weight, int idx){
  if(idx > n || memo[idx][weight]) return;  
  memo[idx][weight] = true;
  dp(weight + arr[idx], idx + 1);
  dp(abs(weight - arr[idx]), idx + 1);
  dp(weight , idx + 1);
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  dp(0,0);
  cin>>m;
  for(int i=0;i<m;i++){
    int target;
    cin>>target;
    if(memo[n][target]) printf("Y ");
    else printf("N ");
   
  }
}