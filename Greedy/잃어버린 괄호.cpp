#include <bits/stdc++.h>
using namespace std;
int main(){
	int sum=0,temp=0,flag=1;
	string arr;
	cin>>arr;
	for(int i = 0 ; arr[i]!=NULL;i++){
		if(arr[i] >= '0' && arr[i]<='9'){
			temp*=10;
			temp+=arr[i]-'0';
		}
		else {
			if(flag == 1) sum+=temp;
			
			else if(flag == -1) sum-=temp;
	
			if(arr[i] == '-') flag=-1;
			
			temp=0;
		}
	}
	if(flag==1) sum+=temp;
	
	else sum-=temp;
	cout<<sum;
} 
