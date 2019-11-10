#include <iostream>

void staircase(int n) {
    char matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = ' ';
        }
        for (int j = 0; j < i + 1; ++j) {
            matrix[i][n - 1 - j] = '#';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main(void) {
    staircase(6);
}
