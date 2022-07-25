#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct point {
    int x;
    int y;
};

bool cmp(const point& l, const point& r) {
    if (l.x != r.x) {
        return l.x < r.x;
    } else {
        return l.y < r.y;
    }
}

bool onLine(point a, point b, point c) {
    vector<point> p = {a, b, c};
    sort(p.begin(), p.end(), cmp);
    int dx1 = b.x - a.x;
    int dy1 = b.y - a.y;
    int dx2 = c.x - b.x;
    int dy2 = c.y - b.y;
    int g1 = gcd(dx1, dy1);
    int g2 = gcd(dx2, dy2);
    dx1 /= g1;
    dy1 /= g1;
    dx2 /= g2;
    dy2 /= g2;
    return dx1 == dx2 && dy1 == dy2;
}

int main() {
    int n;
    cin >> n;
    string yes;
    cin >> yes;
    
    vector<point> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (onLine(p[i], p[j], p[k])) {
                    cout << "On one line (" << p[i].x << ", " << p[i].y << ") (" << p[j].x << ", " << p[j].y << ") (" << p[k].x << ", " << p[k].y << ")\n";
               //     return 0;
                }
            }
        }
    }

    return 0;
}
