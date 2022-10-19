#include <iostream>
#include <algorithm>
using namespace std;
int min_num = 2147000000, n, k, arr[100001], start, last, abst;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	while (last < n) {
		abst = arr[last] - arr[start];
		if (abst >= k) {
			if (abst < min_num)	min_num = abst;
			start++;
		}
		else last++;
	}
	cout << min_num;
}

