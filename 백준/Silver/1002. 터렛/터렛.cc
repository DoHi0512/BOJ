#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int x1, y1, r1, x2, y2, r2;
    double d;
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        int rdiff = r1 - r2 > 0 ? (r1-r2) : (-1) * (r1-r2);

        if (d == 0 && r1 == r2) {
            cout << -1;
        } else if (d > r1 + r2 || d < rdiff) {
            cout << 0;
        } else if (d == r1 + r2 || d == rdiff) {
            cout << 1;
        } else if (d < r1 + r2) {
            cout << 2;
        }
        cout << '\n';
    }
    
    return 0;
}