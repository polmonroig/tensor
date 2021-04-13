#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <stdexcept>


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
        // with a tensor reshape, the length stays the same
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

    /** =================================
     *               OPERATORS
     *  =================================*/

     Tensor<T> operator+(T const& value){

         auto result = Tensor<T>::zeros(shape);
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] + value;
         }

         return result;
     }

     Tensor<T> operator-(T const& value){

         auto result = Tensor<T>::zeros(shape);
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] - value;
         }

         return result;
     }

     Tensor<T> operator*(T const& value){

         auto result = Tensor<T>::zeros(shape);
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] * value;
         }

         return result;
     }

     Tensor<T> operator/(T const& value){

         auto result = Tensor<T>::zeros(shape);
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] / value;
         }

         return result;
     }

     Tensor<T> operator+(Tensor<T> const& other){
         // first of all check that shapes match
         // and throw any exception if necessary
         Tensor<T>::checkShape(shape, other.shape);
         // we create an empty tensor of zeros
         auto result = Tensor<T>::zeros(shape);
         // for each dimension sum each component
         // this implementation of sum does not provide any type
         // of broadcasting
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] + other.data[i];
         }

         return result;
     }



     Tensor<T> operator-(Tensor<T> const& other){
         // first of all check that shapes match
         // and throw any exception if necessary
         Tensor<T>::checkShape(shape, other.shape);
         // we create an empty tensor of zeros
         auto result = Tensor<T>::zeros(shape);
         // for each dimension sum each component
         // this implementation of sum does not provide any type
         // of broadcasting
         for(unsigned int i = 0; i < length; ++i){
             result.data[i] = data[i] - other.data[i];
         }

         return result;
     }


    /** =================================
     *               ARITHMETIC
     *  =================================*/


    T sum() const{
        T count = 0;
        for(auto const& value : data) count += value;
        return count;
    }

    T min() const {
        T minimum = std::numeric_limits<T>::max();
        for(auto const& value : data){
            if(value < minimum) minimum = value;
        }
        return minimum;
    }

    T max() const{
        T maximum = std::numeric_limits<T>::min();
        for(auto const& value : data){
            if(value > maximum) maximum = value;
        }
        return maximum;
    }

    T mean() const{
        return sum() / length;
    }

    /** =================================
     *               STATIC
     *  =================================*/



     static void checkShape(ShapeType const& a, ShapeType const& b){
         if(a.size() != b.size()) throw std::invalid_argument("Tensor shapes do not match");
         for(unsigned int i = 0; i < a.size(); ++i){
             if(a[i] != b[i]) throw std::invalid_argument("Tensor shapes do not match");
         }
     }

     /** =================================
      *               BUILDERS
      *  =================================*/

     static Tensor<T> random(std::shared_ptr<Generator> const& distribution, ShapeType const& size){
        Tensor<T> array;
        array.length = Tensor<T>::getLength(size);
        auto values = distribution->generatePermutations(array.length);

        array.dimensions = size.size();
        array.shape = size;
        array.data = values;
        return array;

    }

    static Tensor<T> zeros(ShapeType const& size){
        return Tensor<T>::fill(size, 0);
    }

    static Tensor<T> ones(ShapeType const& size){
        return Tensor<T>::fill(size, 1);
    }


    static Tensor<T> fill(ShapeType const& size, T const& value){
        Tensor<T> array;
        array.length = Tensor<T>::getLength(size);
        // set variables
        array.dimensions = size.size();
        array.data = std::vector<T>(array.length, value);
        array.shape = size;
        return array;
    }

    static Tensor<T> arange(ShapeValue count){
        auto array = Tensor<T>::zeros({count});
        for(unsigned int i = 0; i < count; ++i){
            array.data[i] = i;
        }
        return array;
    }

    static Tensor<T> linspace(double begin, double end, unsigned int steps){
        // initialize empty array
        auto array = Tensor<T>::zeros({steps});
        // calculate step size and iterate
        double stepSize = (end - begin) / (steps - 1);
        for(unsigned int i = 0; i < steps; ++i){
            array.data[i] = begin + i * stepSize;
        }
        return array;
    }


private:


    static ShapeValue getLength(ShapeType const& size){
        ShapeValue count = 1;
        for(auto const& value : size){
            count *= value;
        }
        return count;
    }

    /** =================================
     *               ATTRIBUTES
     *  =================================*/

    ShapeValue length; // represents the total number of elements
    ShapeValue dimensions; // number of dimensions in the shape
    ShapeType shape; // dimensions on the tensor
    std::vector<T> data; // contains the data

};

#endif
