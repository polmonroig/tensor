#ifndef BINOMIAL_GENERATOR_H
#define BINOMIAL_GENERATOR_H

#include "generator.h"
#include "uniform.h"

class BinomialGenerator : public Generator{



public:

    BinomialGenerator(unsigned int n=100, double probability=0.5);

    void setTrials(unsigned int n);

    void setProbability(double probability);

    double generate();

    void setSeed(BigInt seed);

private:


    UniformGenerator uniform;

    double prob;

    unsigned int trials;



};

#endif
