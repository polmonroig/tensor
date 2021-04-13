#ifndef UNIFORM_GENERATOR_H
#define UNIFORM_GENERATOR_H

#include "generator.h"




/**
 * @class UniformGenerator
 * @brief Random number generator that
 *        generates a sequence of random numbers
 *        based on a specific seed. The numbers generated
 *        here are based on the Linear Congruential Method
 *        D. H . Lehmer (Cambridge, Mass.: Harvard University Press, 1951[141-146])
 *
 * */
class UniformGenerator : public Generator{

public:

     /**
     * @brief generates a probability between 0 and 1
     * @returns a number between 0 and 1
     * */
    double generate();

    /**
     * @brief generate a random number based on a seed
     * @returns the next number in the sequence
     * */
    BigInt generateInteger();


private:



    /**
     * @brief the modulus of the formula
     * */
    static const BigInt m = 2147483647;
    /**
     * @brief the multiplier
     * */
    static const BigInt a = 1664525;

    /**
     * @brief the increment
     * */
    static const BigInt c = 1013904223;


};


#endif //UNIFORM_GENERATOR_H
