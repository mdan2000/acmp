#include <iostream>
#include <vector>

template<typename T>
void printMatrix(std::vector<std::vector<T>>& g) {
    for (const auto& row : g) {
        for (const auto& el : row) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }
}
