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

Im2Col::Im2Col(const int& cache_bytes) {
    kernel_width = 2;
    kernel_height = 2;
    stride = 1;

    input_width = int(sqrt(cache_bytes/sizeof(int)));
    input_height = int(sqrt(cache_bytes/sizeof(int)));
    matrixR = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixG = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixB = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));

    int out_width = (input_width-kernel_width)/stride + 1;
    int out_height = (input_height-kernel_height)/stride + 1;
    matrixO = std::vector<std::vector<int>> (out_width*out_height, std::vector<int> (kernel_height*kernel_width*3));
}

Im2Col::Im2Col(const int& cache_bytes, const int& kernel_width_, const int& kernel_height_, const int& stride_) {
    kernel_width = kernel_width_;
    kernel_height = kernel_height_;
    stride = stride_;

    input_width = int(sqrt(cache_bytes/sizeof(float)));
    input_height = int(sqrt(cache_bytes/sizeof(float)));
    matrixR = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixG = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixB = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));

    int out_width = (input_width-kernel_width)/stride + 1;
    int out_height = (input_height-kernel_height)/stride + 1;
    matrixO = std::vector<std::vector<int>> (out_width*out_height, std::vector<int> (kernel_height*kernel_width*3));
}

Im2Col::Im2Col(const int& input_width_, const int& input_height_, const int& kernel_width_, const int& kernel_height_, const int& stride_) {
    input_width = input_width_;
    input_height = input_height_;
    kernel_width = kernel_width_;
    kernel_height = kernel_height_;
    stride = stride_;

    matrixR = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixG = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));
    matrixB = std::vector<std::vector<int>> (input_width, std::vector<int> (input_height));

    int out_width = (input_width-kernel_width)/stride + 1;
    int out_height = (input_height-kernel_height)/stride + 1;
    matrixO = std::vector<std::vector<int>> (out_width*out_height, std::vector<int> (kernel_height*kernel_width*3));
}

void Im2Col::Init() {
    int value = 1;
    for (int i = 0; i < input_width; ++i) {
        for (int j = 0; j < input_height; ++j) {
            matrixR[i][j] = value;
            matrixG[i][j] = input_width*input_height + value;
            matrixB[i][j] = input_width*input_height*2 + value;
            ++value;
        }
    }
}

void Im2Col::Run() {
    int oi = 0;
    for (int i = 0; i < input_width-(kernel_width-1); i+=stride) {
        for (int j = 0; j < input_height-(kernel_height-1); j+=stride) {
            for (int ki = 0; ki < kernel_width; ++ki) {
                for (int kj = 0; kj < kernel_height; ++kj) {
                    matrixO[oi][kernel_width*ki + kj] = matrixR[i+ki][j+kj];
                    matrixO[oi][kernel_width*ki + kj + kernel_width*kernel_height] = matrixG[i+ki][j+kj];
                    matrixO[oi][kernel_width*ki + kj + kernel_width*kernel_height*2] = matrixB[i+ki][j+kj];
                }
            }
            ++oi;
        }
    }
}

void Im2Col::PrintInfo() {
    std::cout << "Matrix size: " << input_width << "x" << input_height << std::endl;
    std::cout << "Kernel size: " << kernel_width << "x" << kernel_height << std::endl;
    std::cout << std::endl << "Input red matrix: " << std::endl;
    PrintMatrix(matrixR);
    std::cout << std::endl << "Input green matrix: " << std::endl;
    PrintMatrix(matrixG);
    std::cout << std::endl << "Input blue matrix: " << std::endl;
    PrintMatrix(matrixB);
    std::cout << std::endl << "Output matrix: " << std::endl;
    PrintMatrix(matrixO);
}

#endif 