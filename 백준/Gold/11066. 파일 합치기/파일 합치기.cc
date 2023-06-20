#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;t++){
    int arr[501],n,sum[501] = {},dp[501][501] ={};
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
      scanf("%d",&arr[i]);
      sum[i] = sum[i - 1] + arr[i];
    }
   for(int scale=1;scale<n;scale++){
     for(int start = 1; start + scale <= n; start++){
       int end = start + scale;
       dp[start][end] = MAX;
       for(int mid = start; mid < end; mid++){
         dp[start][end] = min(dp[start][end] , dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start -1]);
       }
     }
   }   
  printf("%d\n",dp[1][n]);
  }
}