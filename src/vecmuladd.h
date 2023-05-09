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

#endif