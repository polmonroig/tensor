#include <iostream>
#include <memory>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    auto distribution = std::make_shared<NormalGenerator>();
    distribution->setSeed(4324);

    auto t1 = Tensor<double>::fill({128, 128}, 5);
    std::cout << "Sum: " << t1.sum() << std::endl;
    auto t2 = Tensor<double>::fill({128, 128}, -5);
    std::cout << "Sum: " << t2.sum() << std::endl;
    auto t3 = t1 + t2;
    std::cout << "Sum: " << t3.sum() << std::endl;

}
