#ifndef CHI_SQUARE_GENERATOR_H
#define CHI_SQUARE_GENERATOR_H

#include "generator.h"
#include "gamma.h"

class ChiSquareGenerator : public Generator{



public:

    ChiSquareGenerator(unsigned int freedomDegrees=1);

    void setDegrees(unsigned int freedomDegrees);

    double generate();

    void setSeed(BigInt seed);

private:

    GammaGenerator gamma;

    unsigned int degrees;

};

#endif
