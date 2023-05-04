#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>
#include <vector>

class Kernel {
    public:
        Kernel() {}
        Kernel(const int& cache_bytes) {}
        virtual void Init() = 0;
        virtual void Run() = 0;
        void InitAndRun() { Init(); Run(); }
        virtual void PrintInfo() = 0;
    private:
};

template <typename T>
void PrintMatrix(const std::vector<std::vector<T>> &m) {
    for (int i = 0; i < m.size(); ++i) {
        std::cout << "[ ";
        for (int j = 0; j < m[i].size(); ++j)
            std::cout << m[i][j] << " ";
        std::cout << "]" << std::endl;
    }
}

template <typename T>
void PrintVector(const std::vector<T> &v) {
    std::cout << "[ ";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "]" << std::endl;
}

#endif 