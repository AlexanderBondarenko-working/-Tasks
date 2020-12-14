 #include "basematrix.h"
 #include <cstring>

 template <typename T>
 BaseMatrix<T>::BaseMatrix() : numberOfRows(0), numberOfColums(0), matrix(nullptr) {}

 template <typename T>
 BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfColums)
    : numberOfRows(numberOfRows), numberOfColums(numberOfColums), matrix(nullptr) {}

template <typename T>
BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfColums,
    const T* fillingArray, int sizeOfarray)
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
template <typename T>
BaseMatrix<T>::BaseMatrix(const BaseMatrix<T>& source)
{
    numberOfRows = source.numberOfRows;
    numberOfColums = source.numberOfColums;
    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
            std::memcpy(matrix[indexOflines], source.matrix[indexOflines], (sizeof(T) * numberOfColums));
        }
    }
    else
        matrix = nullptr;
}
template <typename T>
BaseMatrix<T>& BaseMatrix<T>::operator = (const BaseMatrix<T>& source)
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
            std::memcpy(matrix[indexOflines], source.matrix[indexOflines], (sizeof(T) * numberOfColums));
        } 
    }
    else
        matrix = nullptr;

    return *this;
}
template <typename T>
BaseMatrix<T>::~BaseMatrix() {
    if (matrix != nullptr) {
        for (int index = 0; index < numberOfRows; ++index) {
            delete[] matrix[index];
        }
        delete[] matrix;
    }
}
template <typename T>
T scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColum, int tempMatrRow){

    T temporaryRezult = 0;
    for (int lineAndColum = 0; lineAndColum < firstMatrix.numberOfColums; ++lineAndColum) {
        temporaryRezult += (firstMatrix.getElement(tempMatrRow, lineAndColum) * secondMatrix.getElement(lineAndColum, tempMatrColum));
    }

    return temporaryRezult;
}
template <typename T>
BaseMatrix<T> BaseMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const{
    
    if ((this -> numberOfRows != secondMatrix.numberOfColums) 
        && (this-> numberOfColums != secondMatrix.numberOfRows)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    BaseMatrix<T> temporaryMatrix(this-> numberOfRows, secondMatrix.numberOfColums);
    temporaryMatrix.allocateMemory(); // в динамическое выделение

    for (int tempMatrRow = 0; tempMatrRow < temporaryMatrix.numberOfColums; ++tempMatrRow) {
        for (int tempMatrColum = 0; tempMatrColum < temporaryMatrix.numberOfRows; ++tempMatrColum) {
            temporaryMatrix.matrix[tempMatrRow][tempMatrColum] = scalarMultiplication(*this, secondMatrix, tempMatrColum, tempMatrRow);
        }
    }
    return temporaryMatrix;
}

template <typename T>
std::string BaseMatrix<T>::matrixToString() {
    std::string matrixInString;
    matrixInString.reserve(((sizeof(T) * numberOfRows) + numberOfRows + 1) * numberOfColums);

    for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
            matrixInString.append(std::to_string(matrix[indexOflines][indexOfcolums]));
            matrixInString.append(" ");
        }
        matrixInString.append("\n");
    }
    
    return matrixInString;
}
template <typename T>
T BaseMatrix<T>::getElement(int row, int colum) const {
    if (((row < 0) || (row >= numberOfRows)) || ((colum < 0) || (colum >= numberOfColums))) {
        throw std::out_of_range("out of range in getElement");
    }
    
    return matrix[row][colum];
}
template <typename T>
void BaseMatrix<T>::allocateMemory() {
    matrix = new T* [numberOfRows];
    for (int index = 0; index < numberOfRows; ++index) {
        matrix[index] = new T[numberOfColums];
    }
}
template <typename T>
int BaseMatrix<T>::getNumberOfRows() const {
    return numberOfRows;
}
template <typename T>
int BaseMatrix<T>::getNumberOfColums() const {
    return numberOfColums;
}

template class BaseMatrix<int>; 
template class BaseMatrix<double>;