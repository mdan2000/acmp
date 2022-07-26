#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxAdjacent(const vector<vector<int>>& g, int i, int j) {
    int ans = 0;
    for (int d = -1; d < 2; d += 2) {
        if (i + d >= 0 && i + d < g.size() && g[i + d][j] != 0) {
            ans = max(ans, g[i + d][j]);
        }
        if (j + d >= 0 && j + d < g.size() && g[i][j + d] != 0) {
            ans = max(ans, g[i][j + d]);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n, vector<int> (n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    --k;
    --k;
    vector<vector<int>> d(n, vector<int> (n, 0));
    d[0][1] = g[0][1] + g[0][0];
    d[1][0] = g[1][0] + g[0][0];
    if (k == -1) {
        d[0][1] = 0;
        d[1][0] = 0;
        d[0][0] = g[0][0];
    }
    while(k > 0) {
        --k;
        vector<vector<int>> nd = d;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int maxAdjacent = getMaxAdjacent(d, i, j);
                if (maxAdjacent) {
                    nd[i][j] = maxAdjacent + g[i][j];
                } else {
                    nd[i][j] = 0;
                }
            }
        }
        d = nd;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, d[i][j]);
        }
    }

    cout << ans;
}

