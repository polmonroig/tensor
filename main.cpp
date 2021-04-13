#include <iostream>
#include <memory>

#include "tensor/tensor.h"
#include "random/random.h"

int main(){
    auto distribution = std::make_shared<GeometricGenerator>();
    distribution->setSeed(4324);

    Tensor<double> t = Tensor<double>::random(distribution, {128, 64});
    t.print();
}
