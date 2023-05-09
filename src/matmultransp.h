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

#endif