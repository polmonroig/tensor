#include "student-t.h"

/** =================================
 *               PUBLIC
 *  =================================*/


 StudentTGenerator::StudentTGenerator(unsigned int freedomDegrees){
     setDegrees(freedomDegrees);
 }

 void StudentTGenerator::setDegrees(unsigned int freedomDegrees){
     degrees = freedomDegrees;
     chi.setDegrees(degrees);
 }


double StudentTGenerator::generate() {
    double y1 = normal.generate();
    double y2 = chi.generate();
    return y1 / std::sqrt(y2 / degrees);
}


void StudentTGenerator::setSeed(BigInt seed){
    normal.setSeed(seed);
    chi.setSeed(seed);
}
