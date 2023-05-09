#include "relu.h"

Relu::Relu(const int& cache_bytes) {
    row_col_size = int(sqrt(cache_bytes/sizeof(float)));
    matrixI = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
    matrixO = std::vector<std::vector<float>> (row_col_size, std::vector<float> (row_col_size));
}

void Relu::Init() {
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j) {
            if (j%2 == 0)
                matrixI[i][j] = i*j + 0.01;
            else
                matrixI[i][j] = -i*j + 0.01;

            matrixO[i][j] = 0.0;
        }
}

void Relu::Run() {
    float temp;
    for (int i = 0; i < row_col_size; ++i)
        for (int j = 0; j < row_col_size; ++j) {
            if (matrixI[i][j] <= 0)
        		matrixO[i][j] = 0.0;
        	else
        		matrixO[i][j] = matrixI[i][j];
        }
}

void Relu::PrintInfo() {
    std::cout << "Matrix size: " << row_col_size << "x" << row_col_size << std::endl;
    std::cout << std::endl << "Input matrix: " << std::endl;
    PrintMatrix(matrixI);
    std::cout << std::endl << "Output matrix: " << std::endl;
    PrintMatrix(matrixO);
}