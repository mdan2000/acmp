#include <iostream>
#include <vector>


void printMatrix(std::vector<std::vector<int>>& g) {
    for (const auto& row : g) {
        for (const auto& el : row) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }
}
