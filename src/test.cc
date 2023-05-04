#include <string>

#include "im2col.h"
#include "matmul.h"
#include "matmultransp.h"
#include "mattransp.h"
#include "relu.h"
#include "vecmuladd.h"

#define MB 1048576

void test_kernel_once(Kernel* k, const std::string& name) {
    k->InitAndRun();
    std::cout << name << " OK" << std::endl;
}

void test_kernel_100_times(Kernel* k, const std::string& name) {
    k->Init();
    for (int i = 0; i < 100; ++i)
        k->Run();
    std::cout << name << "_100 OK" << std::endl;
}

int main() {
    int cache_size = 4*MB;
    int cache_size_small = 1024;
    std::cout << "Starting tests" << std::endl;
    test_kernel_once(new Im2Col(cache_size), "Im2Col");
    test_kernel_once(new Im2Col(cache_size,4,4,1), "Im2Col_params1");
    test_kernel_once(new Im2Col(1024,1024,4,4,1), "Im2Col_params2");
    test_kernel_once(new MatMul(cache_size), "MatMul");
    test_kernel_once(new MatMulTransp(cache_size), "MatMulTransp");
    test_kernel_once(new MatTransp(cache_size), "MatTransp");
    test_kernel_once(new Relu(cache_size), "Relu");
    test_kernel_once(new VecMulAdd(cache_size), "VecMulAdd");
    test_kernel_100_times(new Im2Col(cache_size_small), "Im2Col");
    test_kernel_100_times(new MatMul(cache_size_small), "MatMul");
    test_kernel_100_times(new MatMulTransp(cache_size_small), "MatMulTransp");
    test_kernel_100_times(new MatTransp(cache_size_small), "MatTransp");
    test_kernel_100_times(new Relu(cache_size_small), "Relu");
    test_kernel_100_times(new VecMulAdd(cache_size_small), "VecMulAdd");
    std::cout << "All tests were successfully completed" << std::endl;
}