#ifndef EXPONENTIAL_GENERATOR_H
#define EXPONENTIAL_GENERATOR_H


#include "generator.h"
#include "uniform.h"


class ExponentialGenerator : public Generator{



public:

    ExponentialGenerator(double lambda=1);

    void setShape(double lambda);

    double generate();

    void setSeed(BigInt seed);

private:

    UniformGenerator uniform;

    double mean;

    static constexpr double MIN_E = 0.00001;

};



#endif
