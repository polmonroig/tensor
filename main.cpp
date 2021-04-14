#include <iostream>
#include <memory>
#include <chrono>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    Tensor<int> b({1, 2, 3, 4, 5});
    b.print();
    auto distribution = std::make_shared<NormalGenerator>();
    auto a = Tensor<double>::random(distribution, {10});
    std::cout << "Tensor has mean: " << a.mean() << std::endl;
    std::cout << "Tensor has std: " << a.std() << std::endl;


}
