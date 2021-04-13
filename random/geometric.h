#ifndef GEOMETRIC_GENERATOR_H
#define GEOMETRIC_GENERATOR_H

#include "generator.h"
#include "uniform.h"

class GeometricGenerator : public Generator{



public:

    GeometricGenerator(double probability=0.5);

    void setProbability(double probability);

    double generate();

    void setSeed(BigInt seed);

private:


    UniformGenerator uniform;

    double prob;

    double lowerLog;



};

#endif
