/*
 * MATRIX MULTIPLICATION
 */

#ifndef MATMUL_H
#define MATMUL_H

#include <cmath>

#include "kernel.h"

class MatMul : public Kernel {
    public:
        MatMul(const int& cache_bytes);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<std::vector<float>> matrixA, matrixB, matrixO;
        int row_col_size;
};

#endif