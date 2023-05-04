/*
 * MATRIX MULTIPLICATION WITH MATRIX B TRANSPOSED
 */

#ifndef MATMULTRANSP_H
#define MATMULTRANSP_H

#include <cmath>

#include "kernel.h"

class MatMulTransp : public Kernel {
    public:
        MatMulTransp(const int& cache_bytes);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<std::vector<float>> matrixA, matrixB, matrixO;
        int row_col_size;
};

MatMulTransp::MatMulTransp(const int& cache_bytes) {
    row_col_size = int(sqrt(cache_bytes/sizeof(float)));
    matrixA = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
    matrixB = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
    matrixO = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
}

void MatMulTransp::Init() {
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j) {
            matrixA[i][j] = j == 0 ? 1.01 : j+0.01;
            matrixB[i][j] = j == 0 ? 1.01 : j+0.01;
        }
}

void MatMulTransp::Run() {
    float temp;
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j) {
            temp = 0.0;
            for (int k = 0; k < row_col_size; ++k)
                temp += matrixA[i][k] * matrixB[j][k];
            matrixO[i][j] = temp;
        }
}

void MatMulTransp::PrintInfo() {
    std::cout << "Matrix size: " << row_col_size << "x" << row_col_size << std::endl;
    std::cout << std::endl << "Input matrix A: " << std::endl;
    PrintMatrix(matrixA);
    std::cout << std::endl << "Input matrix B: " << std::endl;
    PrintMatrix(matrixB);
    std::cout << std::endl << "Output matrix: " << std::endl;
    PrintMatrix(matrixO);
}

#endif