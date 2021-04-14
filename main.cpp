#include <iostream>
#include <memory>
#include <chrono>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    auto a = (Tensor<double>::arange(6).reshape({2, 3}) + 10);
    a.print();
    std::cout << a.argmin() << std::endl;
    auto argmin = a.argmin(0);
    argmin.print();

}
