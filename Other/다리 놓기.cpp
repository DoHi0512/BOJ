#include <iostream>
using namespace std;
int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		int a, b;
		cin >> a >> b;
		unsigned long long int total = 1;
		unsigned long long int fac = 1;
		unsigned long long int min = a >= b ? b : a;
		unsigned long long int max = a >= b ? a : b;
		if (max / 2 < min) min = max - min;
		for (int i = 0; i < min; i++) {
			total *= max;
			max = max - 1;
		}
		for (int i = 1; i <= min; i++) fac *= i;
		cout << total / fac << endl;
	}
}
