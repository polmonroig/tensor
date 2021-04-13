#include "exponential.h"

/** =================================
 *               PUBLIC
 *  =================================*/


ExponentialGenerator::ExponentialGenerator(double lambda){
    setShape(lambda);
}

void ExponentialGenerator::setShape(double lambda){
    mean = 1.0 / lambda;
}

double ExponentialGenerator::generate() {
    auto u = uniform.generate();
    if(u == 0)u = MIN_E;

    return -mean * std::log(u);
}



void ExponentialGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
}
