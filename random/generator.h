#ifndef RAND_GENERATOR
#define RAND_GENERATOR


#include <vector>
#include <cmath>

/**
  * @typedef type definition for a really big unsigned int
  * */
typedef long long unsigned int BigInt;


/**
 * @class Generator
 * @brief A generator explains a set of different distributions
 *        from which the generator can yield variates.
 *
 * */
class Generator{

public:


    /**
     *  @brief generate a random sequence of numbers
     *  @param size is the size of the sequence
     *  @returns the sequence of deviates
     * */
    std::vector<double> generatePermutations(unsigned int size);

    /**
     * @brief generate a random number
     * @returns a random number based on a specific distribution
     * */
    virtual double generate() = 0;


    /**
     * @brief setter for the initial number
     * @param s is the starting number
     * */
    void setSeed(BigInt seed);


    /**
     * @brief the seed of the generators
     * */
    BigInt seed;


};


#endif
