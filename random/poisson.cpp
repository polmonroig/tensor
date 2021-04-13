#include "poisson.h"

/** =================================
 *               PUBLIC
 *  =================================*/


PoissonGenerator::PoissonGenerator(double shape){
    exponential.setShape(shape);
}

void PoissonGenerator::setShape(double shape){
    exponential.setShape(shape);
}


double PoissonGenerator::generate() {
    double sum = 0;
    int counter = 0;
    while(sum < 1){
        sum += exponential.generate();
        counter += 1;
    }

    return counter - 1;
}



void PoissonGenerator::setSeed(BigInt seed){
    exponential.setSeed(seed);
}
