#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    //cout << n << endl;
    cout << "YES" << endl;
    int now = 0;
    int sign = 1;
    int x = 0;
    int d = 0;
    int dsign = 1;

    for (int i = 0; i < n; ++i) {
        now += d;
        if (now >= 10000 && sign == 1) {
            x = -1;
            now = 1;
            sign = -1;
            d = 1;
        }
        if (now >= 10000 && sign == -1) {
            x = 10;
            sign = 1;
            now = -2;
            d = -1001;
            dsign = -1;
        }
        cout << x << ' ' << now << endl;
        x += sign;
        d += dsign;
    }

    return 0;
}
