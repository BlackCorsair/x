#include <iostream>
#include <cmath>
#include <vector>

int calcDiagonalAbsoluteDifference(const std::vector<std::vector<int>>& matrix) {
    int primary_diagonal = 0, secondary_diagonal = 0;
    int row_size = matrix.at(0).size();

    for (int i = 0; i < row_size; i++) {
        const auto& row = matrix.at(i);

        primary_diagonal += row.at(0 + i);
        secondary_diagonal += row.at(row_size - 1 - i);
    }

    return std::abs(primary_diagonal - secondary_diagonal);
}

int main(void) {
    std::vector<std::vector<int>> matrix{{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
    std::cout << calcDiagonalAbsoluteDifference(matrix) << std::endl;
}
