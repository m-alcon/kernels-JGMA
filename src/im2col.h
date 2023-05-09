/*
 * IMAGE TO COLUMNS
 * Algorithm based on:
 * https://leonardoaraujosantos.gitbook.io/artificial-inteligence/machine_learning/deep_learning/convolution_layer/making_faster
 */

#ifndef IM2COL_H
#define IM2COL_H

#include <cmath>

#include "kernel.h"

class Im2Col : public Kernel {
    public:
        Im2Col(const int& cache_bytes);
        Im2Col(const int& cache_bytes, const int& kernel_width_, const int& kernel_height_, const int& stride_);
        Im2Col(const int& input_width_, const int& input_height_, const int& kernel_width_, const int& kernel_height_, const int& stride);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<std::vector<int>> matrixR, matrixG, matrixB, matrixO;
        int input_width, input_height, kernel_width, kernel_height, stride;
        // Suggested stride for maximum computing: 1
        // Padding is always 0
};

#endif 