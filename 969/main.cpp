#include <iostream>

using namespace std;

int main() {
    long long n;
    long long m;
    cin >> n >> m;
    long long ans = 2;
    ans %= m;
    while (n--) {
        ans *= ans;
        ans %= m;
    }
    cout << ans;
}
