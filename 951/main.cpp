#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    int i, j;
};

int manDist(const point a, const point b) {
    return abs(a.i - b.i) + abs(a.j - b.j);
}

int main() {
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;
    vector<point> x;

    for (int i = 0; i < k; ++i) {
        point input;
        cin >> input.i >> input.j;
        input.i--;
        input.j--;
        x.push_back(input);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int minDist = n + m;
            for (const auto& p : x) {
                minDist = min(minDist, manDist(p, {i, j}));
            }
            ans = max(ans, minDist);
        }
    }

    cout << ans;

    return 0;
}
