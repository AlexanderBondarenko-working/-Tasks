 #include "basematrix.h"
 #include <cstring>
 BaseMatrix::BaseMatrix() : numberOfRows(0), numberOfColums(0), matrix(nullptr) {}

 BaseMatrix::BaseMatrix(int numberOfRows, int numberOfColums) 
    : numberOfRows(numberOfRows), numberOfColums(numberOfColums), matrix(nullptr) {}

BaseMatrix::BaseMatrix(int numberOfRows, int numberOfColums,
    const int* fillingArray, int sizeOfarray)
    : numberOfRows(numberOfRows), numberOfColums(numberOfColums)
{
    if ((numberOfRows * numberOfColums) != sizeOfarray) {
        throw std::invalid_argument("invalid array length");
    }

    this -> allocateMemory();

    for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
            matrix[indexOflines][indexOfcolums] = fillingArray[((numberOfColums * indexOflines) + indexOfcolums)];
        }
    }
}

BaseMatrix::BaseMatrix(const BaseMatrix& source)
{
    numberOfRows = source.numberOfRows;
    numberOfColums = source.numberOfColums;
    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
            std::memcpy(matrix[indexOflines], source.matrix[indexOflines], (sizeof(int) * numberOfColums));
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
        for (int index = 0; index < numberOfRows; ++index) {
            delete[] matrix[index];
        }
    }
    delete[] matrix;

    numberOfRows = source.numberOfRows;
    numberOfColums = source.numberOfColums;

    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
            std::memcpy(matrix[indexOflines], source.matrix[indexOflines], (sizeof(int) * numberOfColums));
        } 
    }
    else
        matrix = nullptr;

    return *this;
}

BaseMatrix::~BaseMatrix() {
    if (matrix != nullptr) {
        for (int index = 0; index < numberOfRows; ++index) {
            delete[] matrix[index];
        }
        delete[] matrix;
    }
}

int scalarMultiplication(const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix, int tempMatrColum, int tempMatrRow){

    int temporaryRezult = 0;
    for (int lineAndColum = 0; lineAndColum < firstMatrix.numberOfColums; ++lineAndColum) {
        temporaryRezult += (firstMatrix.getElement(tempMatrRow, lineAndColum) * secondMatrix.getElement(lineAndColum, tempMatrColum));
    }

    return temporaryRezult;
}

BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix) {
    
    if ((firstMatrix.numberOfRows != secondMatrix.numberOfColums) 
        && (firstMatrix.numberOfColums != secondMatrix.numberOfRows)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    BaseMatrix temporaryMatrix(firstMatrix.numberOfRows, secondMatrix.numberOfColums);
    temporaryMatrix.allocateMemory(); // в динамическое выделение

    for (int tempMatrRow = 0; tempMatrRow < temporaryMatrix.numberOfColums; ++tempMatrRow) {
        for (int tempMatrColum = 0; tempMatrColum < temporaryMatrix.numberOfRows; ++tempMatrColum) {
            temporaryMatrix.matrix[tempMatrRow][tempMatrColum] = scalarMultiplication(firstMatrix, secondMatrix, tempMatrColum, tempMatrRow);
        }
    }
    return temporaryMatrix;
}


std::string BaseMatrix::matrixToString() {
    std::string matrixInString;
    matrixInString.reserve(((sizeof(int) * numberOfRows) + numberOfRows + 1) * numberOfColums);

    for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
            matrixInString.append(std::to_string(matrix[indexOflines][indexOfcolums]));
            matrixInString.append(" ");
        }
        matrixInString.append("\n");
    }
    
    return matrixInString;
}

int BaseMatrix::getElement(int line, int colum) const { // проверка на выход за пределы
    
    return matrix[line][colum];
}

void BaseMatrix::allocateMemory() {
    matrix = new int* [numberOfRows];
    for (int index = 0; index < numberOfRows; ++index) {
        matrix[index] = new int[numberOfColums];
    }
}

int BaseMatrix::getNumberOfRows() const {
    return numberOfRows;
}

int BaseMatrix::getnumberOfColums() const {
    return numberOfColums;
}