#ifndef GAMMA_GENERATOR_H
#define GAMMA_GENERATOR_H


#include "generator.h"
#include "uniform.h"
#include "exponential.h"


class GammaGenerator : public Generator{



public:

    GammaGenerator(double a=1, double s=1);

    void setOrder(double a);

    double generate();

    void setSeed(BigInt seed);

private:

    ExponentialGenerator exponential;
    UniformGenerator uniform;


    double order;

    double scale;

    static constexpr double MIN_E = 0.00001;

};



#endif
