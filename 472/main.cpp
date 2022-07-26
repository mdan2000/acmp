#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int ans = -1;
    for (int i = 0; i < n - 1; ++i) {
        int minus = (x[i + 1] - x[i]) * (i + 1);
        if (minus <= m) {
            m -= minus;
        } else {
            int add = m / (i + 1);
            ans = x[i] + add;
            m = 0;
            break;
        }
    }
    if (ans == -1) {
        int add = m / n;
        ans = x.back() + add;
        cout << ans;
    }
    else {
        cout << ans;
    }
}

