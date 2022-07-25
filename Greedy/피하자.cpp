#include <bits/stdc++.h>
using namespace std;
int ans[2],sum[2];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		sum[temp%2]++;
		ans[temp%2] += sum[((temp+1)%2)];
	}
	cout<<min(ans[0],ans[1]);
	
}
