#ifndef NORMAL_GENERATOR_H
#define NORMAL_GENERATOR_H


#include "generator.h"
#include "uniform.h"


class NormalGenerator : public Generator{



public:


    NormalGenerator(double mean=0, double standardDeviation=1);


    double generate();

    void setSeed(BigInt seed);


private:

    UniformGenerator uniform;

    bool hasAlternative;
    double alternativeDeviate;

    double average;
    double deviation;

};



#endif
