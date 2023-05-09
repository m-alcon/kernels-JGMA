/*
 * RECTIFIED LINEAR UNIT
 */

#ifndef RELU_H
#define RELU_H

#include <cmath>

#include "kernel.h"

class Relu : public Kernel {
    public:
        Relu(const int& cache_bytes);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<std::vector<float>> matrixI, matrixO;
        int row_col_size;
};

#endif