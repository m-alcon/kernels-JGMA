/*
 * MATRIX TRANSPOSE
 */

#ifndef MATTRANSP_H
#define MATTRANSP_H

#include <cmath>

#include "kernel.h"

class MatTransp : public Kernel {
    public:
        MatTransp(const int& cache_bytes);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<std::vector<float>> matrixA, matrixO;
        int row_col_size;
};

#endif