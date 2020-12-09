#include "basematrix.h"
BaseMatrix::BaseMatrix() : numberOflines(0), numberOfcolums(0), matrix(nullptr) {}

BaseMatrix::BaseMatrix(const int numberOflines, const int numberOfcolums,
    const int* fillingArray, const int sizeOfarray)
    : numberOflines(numberOflines), numberOfcolums(numberOfcolums)
{
    if ((numberOflines * numberOfcolums) != sizeOfarray) {
        throw std::invalid_argument("invalid array length");
    }

    matrix = new int* [numberOflines];
    for (int index = 0; index < numberOflines; ++index) {
        matrix[index] = new int[numberOfcolums];
    }

    for (int indexOflines = 0; indexOflines < numberOflines; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfcolums; ++indexOfcolums) {
            matrix[indexOflines][indexOfcolums] = fillingArray[((numberOfcolums * indexOflines) + indexOfcolums)];
        }
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

BaseMatrix& BaseMatrix::operator= (const BaseMatrix& source)
{
    if (this == &source) {
        return *this;
    }

    if (matrix != nullptr) {
        for (int index = 0; index < numberOflines; ++index) {
            delete[] matrix[index];
        }
    }

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

    return *this;
}

BaseMatrix::~BaseMatrix() {
    if (matrix != nullptr) {
        for (int index = 0; index < numberOflines; ++index) {
            delete[] matrix[index];
        }
    }
}