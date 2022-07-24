#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getNumber(int n, int k) {
    string res = "";
    while (n) {
        if (n % k < 10) {
            res += (char)('0' + n % k);
        } else {
            res += (char)((int)'A' + ((n % k) - 10));
        }
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int d, m, y;
    char s1, s2;
    cin >> d >> s1 >> m >> s2 >> y;
    cout << getNumber(d, d+1) << '/' << getNumber(m, d+1) << '/' << getNumber(y, d+1);
}
