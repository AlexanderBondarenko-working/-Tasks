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
    numberOflines = source.numberOflines;
    numberOfcolums = source.numberOfcolums;
    if (source.matrix) {
        matrix = new int* [numberOflines];
        for (int index = 0; index < numberOflines; ++index) {
            matrix[index] = new int[numberOfcolums];
        }
        for (int indexOflines = 0; indexOflines < numberOflines; ++indexOflines) {
            for (int indexOfcolums = 0; indexOfcolums < numberOfcolums; ++indexOfcolums) {
                matrix[indexOflines][indexOfcolums] = source.matrix[indexOflines][indexOfcolums];
            }
        }
    }
    else
        matrix = nullptr;
}



BaseMatrix::~BaseMatrix() {
    if (matrix != nullptr) {
        for (int index = 0; index < numberOflines; ++index) {
            delete[] matrix[index];
        }
    }
}