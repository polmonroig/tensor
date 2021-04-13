#include <iostream>
#include <memory>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    auto t1 = Tensor<double>::linspace(0, 10, 5);
    t1.print();
    t1 = -t1;
    t1.print();

}
