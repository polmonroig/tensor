#include "generator.h"


/** =================================
 *               PUBLIC
 *  =================================*/

std::vector<double> Generator::generatePermutations(unsigned int size) {
    std::vector<double> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}


void Generator::setSeed(BigInt s){
    seed = s;
}
