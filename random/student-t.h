#ifndef STUDENT_T_GENERATOR_H
#define STUDENT_T_GENERATOR_H

#include "generator.h"
#include "normal.h"
#include "chi-square.h"

class StudentTGenerator : public Generator{



public:

    StudentTGenerator(unsigned int freedomDegrees=1);

    void setDegrees(unsigned int freedomDegrees);

    double generate();

    void setSeed(BigInt seed);

private:


    NormalGenerator normal;
    ChiSquareGenerator chi;

    unsigned int degrees;


};

#endif
