#include "geometric.h"

/** =================================
 *               PUBLIC
 *  =================================*/


 GeometricGenerator::GeometricGenerator(double probability){
     setProbability(probability);
 }

 void GeometricGenerator::setProbability(double probability){
     prob = probability;
     lowerLog = std::log(1 - prob); // precalculate logarithm
 }


double GeometricGenerator::generate() {
    return std::ceil(std::log(uniform.generate()) / lowerLog);
}


void GeometricGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
}
