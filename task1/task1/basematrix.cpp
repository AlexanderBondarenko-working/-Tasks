#include "basematrix.h"

BaseMatrix::BaseMatrix() : numberOflines(0), numberOfcolums(0), matrix(nullptr) {}

BaseMatrix::BaseMatrix(const int numberOflines, const int numberOfcolums,
    const int* fillingArray, const int sizeOfarray)
    : numberOflines(numberOflines), numberOfcolums(numberOfcolums)
{
    matrix = new int* [numberOflines];
    for (int index = 0; index < numberOflines; ++index) {
        matrix[index] = new int[numberOfcolums];
    }
}

BaseMatrix::BaseMatrix(const BaseMatrix& source)
{
   
}



BaseMatrix::~BaseMatrix() {
    
}