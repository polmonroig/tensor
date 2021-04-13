#include "gamma.h"

/** =================================
 *               PUBLIC
 *  =================================*/


GammaGenerator::GammaGenerator(double a, double s){
    order = a;
    scale = s;
    exponential.setShape(order);
}

void GammaGenerator::setOrder(double a){
    order = a;
}

double GammaGenerator::generate() {
    if(order == 1){
        return exponential.generate() * scale;
    }
    double x = 0;
    double y;
    double keep_iterating = true;
    // it is performed < 1.902 times when a >= 3
    while(keep_iterating){
        auto u = uniform.generate();
        if(u == 0)u = MIN_E;
        y = std::tan(M_PI * u);
        x = std::sqrt(2.0 * order  - 1.0) * y + order - 1;
        keep_iterating = x <= 0;
        if(!keep_iterating){
            auto v = uniform.generate();
            if(v == 0)v = MIN_E;
            double value = (1 + y*y) * std::exp((order - 1) * std::log(x / (order - 1)) - std::sqrt(2 * order - 1) * y);
            keep_iterating = v > value;
        }

    }


    return x * scale;
}


void GammaGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
    exponential.setSeed(seed);
}
