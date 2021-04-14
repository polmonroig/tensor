#include <iostream>
#include <memory>
#include <chrono>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    Tensor<int> b({1, 2, 3, 4, 5});
    b.print();
    auto a = (Tensor<double>::arange(6).reshape({2, 3}) + 10);
    a.print();
    std::cout << a.argmin() << std::endl;
    auto argmin = a.argmin(0);
    argmin.print();

}
