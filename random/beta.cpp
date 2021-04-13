#include "beta.h"

/** =================================
 *               PUBLIC
 *  =================================*/


BetaGenerator::BetaGenerator(double a, double b){
    setShape(a, b);
 }

void BetaGenerator::setShape(double a, double b){
    alpha = a;
    beta = b;
    alphaGenerator.setOrder(alpha);
    betaGenerator.setOrder(beta);
    alphaPow = 1 / alpha;
    betaPow = 1 / alpha;
}



double BetaGenerator::generate() {
    if(alpha < 1 || beta < 1){
        double y1, y2;
        y1 = y2 = 2;

        while(y1 + y2 > 1){
            y1 = std::pow(uniform.generate(), alphaPow);
            y2 = std::pow(uniform.generate(), betaPow);
        }
        return y1 / (y1 + y2);
    }
    else{
        double x1 = alphaGenerator.generate();
        double x2 = betaGenerator.generate();
        return x1 / (x1 + x2);
    }

}


void BetaGenerator::setSeed(BigInt seed){
    uniform.setSeed(seed);
    alphaGenerator.setSeed(seed);
    betaGenerator.setSeed(seed * 2);
}
