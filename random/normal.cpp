#include "normal.h"

/** =================================
 *               PUBLIC
 *  =================================*/



NormalGenerator::NormalGenerator(double mean, double standardDeviation){
    average = mean;
    deviation = standardDeviation;
    hasAlternative = false;
    alternativeDeviate = -1;
}



double NormalGenerator::generate() {
    // every generate call generates 2 deviates
    // so we can save the value for next call,
    // thus making the complexity of n * generates = O(n / 2)
    if(hasAlternative){
        hasAlternative = false;
        return alternativeDeviate;
    }

    double s = 1;
    double v1, v2;
    while(s >= 1){
        v1 = uniform.generate() * 2.0 - 1.0;
        v2 = uniform.generate() * 2.0 - 1.0;
        s = v1*v1 + v2*v2;
    }
    if(s == 0) return 0;
    else{
        auto x1 = v1 * std::sqrt((-2 * std::log(s)) / s);
        x1 = deviation * x1 + average;
        auto x2 = v2 * std::sqrt((-2 * std::log(s)) / s);
        hasAlternative = true;
        alternativeDeviate = x2;
        return x1; // no need to calculate x2 random variable
    }
}




void NormalGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
}
