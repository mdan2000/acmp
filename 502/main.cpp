#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    vector<int> dp(n + 1, 0);
    for (int j = 0; j < n; ++j) {
        vector<int> newDP = dp;
        for (int i = 0; i < n; ++i) {
            for (int d = i; d < n; ++d) {
                newDP[d - i] = max(newDP[d - i], dp[d + 1] + g[i][j]);
            }
        }
        dp = newDP;
    }
    cout << dp[0];
    return 0;
}

