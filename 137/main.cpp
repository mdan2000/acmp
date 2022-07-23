#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Floid(vector<vector<int>>& g) {
    for (int k = 0; k < g.size(); ++k) {
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g.size(); ++j) {
                if (g[i][k] && g[k][i]) {
                    if (g[i][j] == 0) {
                        g[i][j] = g[i][k] + g[k][j];
                    } else {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n, 0));

    for (auto& row : g) {
        for (auto& el : row) {
            cin >> el;
        }
    }
    
    Floid(g);
    vector<vector<int>> newg = g;
    Floid(newg);
    
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g.size(); ++j) {
            if (g[i][j] != 0) {
                if (g[i][j] == newg[i][j]) {
                    cout << 1;
                } else {
                    cout << 2;
                }
            } else {
                cout << 0;
            }
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
