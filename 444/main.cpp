#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int digitLen(int n) {
    int len = 0;
    if (n < 0) {
        ++len;
        n *= -1;
    }

    if (n == 0) {
        ++len;
    }

    while (n != 0) {
        ++len;
        n /= 10;
    }
    return len;
}


void printBest(const vector<int>& x, int l, int r, bool last = false) {
    int lenDots = 0;
    int lenAll = 0;

    const int dotsSpaceAndCommasLen = 7;
    const int commaAndSpaceLen = 2;

    lenDots += digitLen(l) + digitLen(r) + dotsSpaceAndCommasLen;

    lenAll += digitLen(l);
    for (int i = l + 1; i <= r; ++i) {
        lenAll += commaAndSpaceLen;
        lenAll += digitLen(i);
        if (lenAll > lenDots) {
            break;
        }
    }
    if (lenDots <= lenAll) {
        cout << l << ", ..., " << r;
    } else {
        cout << l;
        for (int i = l + 1; i <= r; ++i) {
            cout << ", " << i;
        }
    }
    if (!last) {
        cout << ", ";
    }
}

void solve(const vector<int>& x) {
    int l = 0;
    for (int i = 1; i < x.size(); ++i) {
        if (x[i] != x[i - 1] + 1) {
            if (l != i - 1) {
                printBest(x, x[l], x[i - 1]);
            } else {
                cout << x[i - 1] << ", ";
            }
            l = i;
        }
    }
    if (l != x.size() - 1) {
        printBest(x, x[l], x.back(), true);
    } else {
        cout << x.back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& el : x) {
        cin >> el;
    }

    sort(x.begin(), x.end());
    auto last = unique(x.begin(), x.end());
    x.erase(last, x.end());

    solve(x);
}

