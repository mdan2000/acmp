#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    bool isFirst = false;
    for (int i = 2; i * 2 <= n; ++i) {
        if (isPrime(i) && isPrime(n - i)) {
            if (isFirst) {
                //cout << n;
                //isFirst = true;
            }
            //cout << "=" << i << "+" << n-i;
            ++ans;
        }
    }
    //if (isFirst) {
    //    cout << n << " непредставимо";
    //}
    cout << ans;

    return 0;
}
