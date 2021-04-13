#include "uniform.h"


/** =================================
 *               PUBLIC
 *  =================================*/



double UniformGenerator::generate(){
    return (generateInteger() * 1.0) / m;
}

BigInt UniformGenerator::generateInteger() {
    auto r = (seed * a + c) % m;
    seed = r;
    return r;
}
