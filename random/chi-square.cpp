#include "chi-square.h"

/** =================================
 *               PUBLIC
 *  =================================*/


 ChiSquareGenerator::ChiSquareGenerator(unsigned int freedomDegrees){
     setDegrees(freedomDegrees);
 }

 void ChiSquareGenerator::setDegrees(unsigned int freedomDegrees){
     degrees = freedomDegrees;
     gamma.setOrder(float(degrees) / 2.0);
 }



double ChiSquareGenerator::generate() {
    return gamma.generate() * 2.0;
}


void ChiSquareGenerator::setSeed(BigInt seed){
    gamma.setSeed(seed);
}
