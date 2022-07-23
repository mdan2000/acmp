#include "helper.h"

#include <iostream>
#include <vector>

using namespace std;

void TestMatrixPrint() {
    {
        vector<vector<int>> g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        printMatrix(g);
    }
}

void TEST() {
    TestMatrixPrint();
}

int main() {
    TEST();
}
