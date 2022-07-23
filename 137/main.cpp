//#include "../helper/helper.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long inf = 1e9;

void Floid(vector<vector<long long>>& g) {
    for (int k = 0; k < g.size(); ++k) {
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g.size(); ++j) {
                if (g[i][k] != inf && g[k][j] != inf)
                g[i][j] = min(inf, max(-inf, min(g[i][j], g[i][k] + g[k][j])));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> g(n, vector<long long>(n, inf));

    for (auto& row : g) {
        for (auto& el : row) {
            cin >> el;
            if (el == 0) {
                el = inf;
            }
        }
    }

    Floid(g);
    vector<vector<long long>> newg = g;
    Floid(newg);
    
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g.size(); ++j) {
            if (g[i][j] <= 100*100) {
                if (g[i][j] == newg[i][j] && newg[i][j] != -inf) {
                    cout << 1;
                } else {
                    cout << 2;
                }
            } else if (i != j) {
                cout << 0;
            } else {
                cout << 1;
            }
            cout << ' ';
        }
        cout << endl;
    }

//    cout << endl;
//    printMatrix(g);
//    cout << endl;
//    printMatrix(newg);

    return 0;
}
