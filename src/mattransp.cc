#include "mattransp.h"

MatTransp::MatTransp(const int& cache_bytes) {
    row_col_size = int(sqrt(cache_bytes/sizeof(float)));
    matrixA = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
    matrixO = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
}

void MatTransp::Init() {
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j)
            matrixA[i][j] = j == 0 ? 1.01 : j+0.01;
}

void MatTransp::Run() {
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j)
            matrixO[i][j] = matrixA[j][i];
}

void MatTransp::PrintInfo() {
    std::cout << "Matrix size: " << row_col_size << "x" << row_col_size << std::endl;
    std::cout << std::endl << "Input matrix: " << std::endl;
    PrintMatrix(matrixA);
    std::cout << std::endl << "Output matrix: " << std::endl;
    PrintMatrix(matrixO);
}
