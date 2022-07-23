#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    string commands = "NSWEUD";
    map<char, string> m;

    for (const auto& c : commands) {
        getline(cin, m[c]);
    }

    char command;
    int n;

    cin >> command >> n;

    vector<vector<int>> din(n + 1, vector<int> (128, 0));

    for (int i = 1; i <= n; ++i) {
        for (const auto& c : commands) {
            for (const auto& mc : m.at(c)) {
                din[i][c] += din[i - 1][mc];
            }
            din[i][c]++;
        }
    }

    cout << din[n][command];

    return 0;
}
