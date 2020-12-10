 #include "basematrix.h"
 BaseMatrix::BaseMatrix() : numberOflines(0), numberOfcolums(0), matrix(nullptr) {}

 BaseMatrix::BaseMatrix(const int numberOflines, const int numberOfcolums) 
    : numberOflines(numberOflines), numberOfcolums(numberOfcolums) 
 {
     matrix = new int* [numberOflines];
     for (int index = 0; index < numberOflines; ++index) {
         matrix[index] = new int[numberOfcolums];
     }
 }

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

BaseMatrix& BaseMatrix::operator = (const BaseMatrix& source)
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

BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix) {
    if ((firstMatrix.numberOflines != secondMatrix.numberOfcolums) 
        && (firstMatrix.numberOfcolums != secondMatrix.numberOflines)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    BaseMatrix temporaryMatrix(firstMatrix.numberOflines, secondMatrix.numberOfcolums);
    int compos;

    for (int resIndexline = 0; resIndexline < temporaryMatrix.numberOfcolums; ++resIndexline) {
        for (int resIndexColum = 0; resIndexColum < temporaryMatrix.numberOflines; ++resIndexColum) {
            compos = 0;
            for (int lineAndColum = 0; lineAndColum < firstMatrix.numberOfcolums; ++lineAndColum) {
                compos += (firstMatrix.matrix[resIndexline][lineAndColum] * secondMatrix.matrix[lineAndColum][resIndexColum]);
            }
            temporaryMatrix.matrix[resIndexline][resIndexColum] = compos;
        }
    }
    return temporaryMatrix;
}

void BaseMatrix::out() {
    for (int indexOflines = 0; indexOflines < numberOflines; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfcolums; ++indexOfcolums) {
            std::cout << matrix[indexOflines][indexOfcolums] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}