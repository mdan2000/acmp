#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int m;
    cin >> m;
    unordered_map<string, vector<string>> g;

    for (int i = 0; i < m; ++i) {
        string from, to;
        string tmp;
        cin >> from >> tmp >> to;
        g[from].push_back(to);
    }

    string s, f;
    cin >> s >> f;

    unordered_map<string, int> d;

    d[s] = 0;
    queue<string> q;
    q.push(s);

    while (!q.empty()) {
        string from = q.front();
        q.pop();

        for (const auto& to : g[from]) {
            if (d.find(to) == d.end()) {
                d[to] = d[from] + 1;
                q.push(to);
            }
        }
    }

    if (d.find(f) != d.end()) {
        cout << d[f];
    } else {
        cout << -1;
    }

    return 0;
}
