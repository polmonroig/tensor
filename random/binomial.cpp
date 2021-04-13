#include "binomial.h"

/** =================================
 *               PUBLIC
 *  =================================*/


BinomialGenerator::BinomialGenerator(unsigned int n, double probability){
    setTrials(n);
    setProbability(probability);
}

void BinomialGenerator::setTrials(unsigned int n){
    trials = n;
}


void BinomialGenerator::setProbability(double probability){
    prob = probability;
}

double BinomialGenerator::generate() {
    unsigned int count = 0;
    for(unsigned int i = 0; i < trials; ++i){
        auto u = uniform.generate();
        if(u < prob) count++; // count how many are below
    }

    return count;
}


void BinomialGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
}
