/*
 * VECTOR MULTIPLY ADD
 */

#ifndef VECMULADD_H
#define VECMULADD_H

#include "kernel.h"

class VecMulAdd : public Kernel {
    public:
        VecMulAdd(const int& cache_bytes);
        void Init();
        void Run();
        void PrintInfo();
    private:
        std::vector<float> vectorA, vectorB;
        int vector_size;
        float result;
};

VecMulAdd::VecMulAdd(const int& cache_bytes) {
    vector_size = int(cache_bytes/sizeof(float));
    vectorA = std::vector<float> (vector_size);
    vectorB = std::vector<float> (vector_size);
}

void VecMulAdd::Init() {
    for (int i = 1; i < vector_size; ++i) {
        vectorA[i] = i == 0 ? 1.01 : i + 0.01;
        vectorB[i] = -0.01;
    }
}

void VecMulAdd::Run() {
    result = 0;
    for (int i = 0; i < vector_size; ++i)
        result += vectorA[i] * vectorB[i];
}

void VecMulAdd::PrintInfo() {
    std::cout << "std::vector size: " << vector_size << std::endl;
    std::cout << std::endl << "Input std::vector A: " << std::endl;
    PrintVector(vectorA);
    std::cout << std::endl << "Input std::vector B: " << std::endl;
    PrintVector(vectorB);
    std::cout << std::endl << "Result: " << result << std::endl;
}

#endif