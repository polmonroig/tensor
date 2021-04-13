#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <vector>
#include <memory>

#include "../random/random.h"

typedef unsigned int ShapeValue;
typedef std::vector<ShapeValue> ShapeType;

template<class T>
class Tensor{


public:


    void print() const{
        std::cout << "Tensor of shape (";
        for(unsigned int i = 0; i < dimensions - 1; ++i){
            std::cout << shape[i] << ", ";
        }
        std::cout << shape[dimensions - 1] << ')' << std::endl;
        unsigned int dataIndex = 0;
        printDimension(0, dataIndex); // start at 0s
        std::cout << std::endl; // last endline
    }

    void reshape(ShapeType const& size){
        dimensions = size.size();
        shape = size;
    }

    void printDimension(unsigned int dim, unsigned int& dataIndex) const{
        std::cout << '[';
        if(dim == dimensions - 1){ // base case dim
            auto end = shape[dim] + dataIndex;
            while(dataIndex < end){
                std::cout << data[dataIndex] << ", ";
                dataIndex++;
            }
        }
        else{
            for(unsigned int i = 0; i < shape[dim]; ++i){
                printDimension(dim + 1, dataIndex);
            }
        }
        std::cout << ']';
    }

    static Tensor<T> random(std::shared_ptr<Generator> const& distribution, ShapeType const& size){
        Tensor<T> array;
        ShapeValue count = Tensor<T>::countShape(size);
        auto values = distribution->generatePermutations(count);

        array.dimensions = size.size();
        array.shape = size;
        array.data = values;
        return array;

    }

    static Tensor<T> zeros(ShapeType const& size){
        Tensor<T> array;
        ShapeValue count = Tensor<T>::countShape(size);
        // set variables
        array.dimensions = size.size();
        array.data = std::vector<T>(count, 2);
        array.shape = size;
        return array;
    }


    static ShapeValue countShape(ShapeType const& size){
        ShapeValue count = 1;
        for(auto const& value : size){
            count *= value;
        }
        return count;
    }


private:

    ShapeValue dimensions;
    ShapeType shape;
    std::vector<T> data;

};

#endif
