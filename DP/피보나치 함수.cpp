#include <iostream>
using namespace std;
int arr[41][2];
int main(){
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int n;
		cin>>n;
		arr[0][0]=1;
		arr[1][1]=1;
		for(int i=2;i<=n;i++){
			arr[i][0]=arr[i-1][0]+arr[i-2][0];
			arr[i][1]=arr[i-1][1]+arr[i-2][1];
		}
		printf("%d %d\n",arr[n][0],arr[n][1]);
	}
}
