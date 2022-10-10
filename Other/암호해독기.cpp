#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, temp;
	char arr[53] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
	}
	string tarr;
	cin.ignore();
	getline(cin, tarr);
	for (int i = 0; i < n; i++) {
		if (tarr[i] == ' ') {
			arr[0]--;
		}
		else if (tarr[i] >= 'A' && tarr[i] <= 'Z') {
			arr[tarr[i] - 64]--;
		}
		else if (tarr[i] >= 'a' && tarr[i] <= 'z') {
			arr[tarr[i] - 70]--;
		}
	}
	for (int i = 0; i < 53; i++) {
		if (arr[i] != 0) {
			cout << "n" << endl;
			return 0;
		}
	}
	cout << "y";

}
