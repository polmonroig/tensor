#ifndef BETA_GENERATOR_H
#define BETA_GENERATOR_H

#include "generator.h"
#include "gamma.h"

class BetaGenerator : public Generator{



public:

    BetaGenerator(double a=1, double b=1);

    void setShape(double a, double b);

    double generate();

    void setSeed(BigInt seed);

private:

    GammaGenerator alphaGenerator;
    GammaGenerator betaGenerator;
    GammaGenerator uniform;

    double alpha;
    double beta;

    double alphaPow;
    double betaPow;

};

#endif
