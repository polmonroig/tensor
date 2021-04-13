#ifndef POISSON_GENERATOR_H
#define POISSON_GENERATOR_H


#include "generator.h"
#include "exponential.h"


class PoissonGenerator : public Generator{



public:

    PoissonGenerator(double shape=1);

    void setShape(double shape);

    double generate() ;


    void setSeed(BigInt seed);


private:

    ExponentialGenerator exponential;


};



#endif
