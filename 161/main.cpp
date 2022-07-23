#include <iostream>
#include <set>
#include <vector>

using namespace std;

int ks(set<int>& ost, int k) {
    auto it = ost.end();
    --it;
    while (k--) {
        --it;
    }
    return *it;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& el : x) {
        cin >> el;
    }

    set<int> ost;
    for (int i = 1; i <= n; ++i) {
        ost.insert(i);
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
        int el = ks(ost, x[i]);
        ans[i] = el;
        ost.erase(el);
    }

    for (const auto& el : ans) {
        cout << el << ' ';
    }
}
