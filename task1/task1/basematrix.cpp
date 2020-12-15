 #include "basematrix.h"
 #include <cstring>

 template <typename T>
 BaseMatrix<T>::BaseMatrix() : numberOfRows(0), numberOfColumns(0), matrix(nullptr) {}

 template <typename T>
 BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfColumns)
    : numberOfRows(numberOfRows), numberOfColumns(numberOfColumns)
 {
     allocateMemory();
 }

template <typename T>
BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfColumns,
    const T* fillingArray, int sizeOfarray)
    : numberOfRows(numberOfRows), numberOfColumns(numberOfColumns)
{
    if ((numberOfRows * numberOfColumns) != sizeOfarray) {
        throw std::invalid_argument("invalid array length");
    }

    this -> allocateMemory();

    for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
        for (int indexOfcolumns = 0; indexOfcolumns < numberOfColumns; ++indexOfcolumns) {
            matrix[indexOfRows][indexOfcolumns] = fillingArray[((numberOfColumns * indexOfRows) + indexOfcolumns)];
        }
    }
}
template <typename T>
BaseMatrix<T>::BaseMatrix(const BaseMatrix<T>& source)
{
    numberOfRows = source.numberOfRows;
    numberOfColumns = source.numberOfColumns;
    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
            std::memcpy(matrix[indexOfRows], source.matrix[indexOfRows], (sizeof(T) * numberOfColumns));
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
    numberOfColumns = source.numberOfColumns;

    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
            std::memcpy(matrix[indexOfRows], source.matrix[indexOfRows], (sizeof(T) * numberOfColumns));
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
std::string BaseMatrix<T>::matrixToString() {
    std::string matrixInString;
    matrixInString.reserve(((sizeof(T) * numberOfRows) + numberOfRows + 1) * numberOfColumns);

    for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
        for (int indexOfColumns = 0; indexOfColumns < numberOfColumns; ++indexOfColumns) {
            matrixInString.append(std::to_string(matrix[indexOfRows][indexOfColumns]));
            matrixInString.append(" ");
        }
        matrixInString.append("\n");
    }
    
    return matrixInString;
}
template <typename T>
T BaseMatrix<T>::getElement(int row, int column) const {
    if (((row < 0) || (row >= numberOfRows)) || ((column < 0) || (column >= numberOfColumns))) {
        throw std::out_of_range("out of range in getElement");
    }
    
    return matrix[row][column];
}
template <typename T>
void BaseMatrix<T>::allocateMemory() {
    matrix = new T* [numberOfRows];
    for (int index = 0; index < numberOfRows; ++index) {
        matrix[index] = new T[numberOfColumns]{ 0 };
    }
}
template <typename T>
int BaseMatrix<T>::getNumberOfRows() const {
    return numberOfRows;
}
template <typename T>
int BaseMatrix<T>::getNumberOfColumns() const {
    return numberOfColumns;
}

template <typename T>
void BaseMatrix<T>::setElement(T element, int row, int column) {
    if (((row < 0) || (row >= numberOfRows)) || ((column < 0) || (column >= numberOfColumns))) {
        throw std::out_of_range("out of range in getElement");
    }

    matrix[row][column] = element;
}

template <typename T>
BaseMatrix<T>* BaseMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const {
    if ((this->numberOfRows != secondMatrix.numberOfColumns)
        && (this->numberOfColumns != secondMatrix.numberOfRows)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    return this->matrixMultiplication(*this, secondMatrix);
}

template <typename T>
BaseMatrix<T>* BaseMatrix<T>::matrixMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix) const{
    BaseMatrix<T> * temporaryMatrix = new BaseMatrix<T>(this->getNumberOfRows(), secondMatrix.getNumberOfColumns());

    for (int tempMatrRow = 0; tempMatrRow < temporaryMatrix->getNumberOfColumns(); ++tempMatrRow) {
        for (int tempMatrColumn = 0; tempMatrColumn < temporaryMatrix->numberOfRows; ++tempMatrColumn) {
            temporaryMatrix->setElement(secondMatrix.scalarMultiplication(firstMatrix, secondMatrix, tempMatrColumn, tempMatrRow), tempMatrRow, tempMatrColumn);
        }
    }
    return temporaryMatrix;
}

template <typename T>
T BaseMatrix<T>::scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColumn, int tempMatrRow) const {
    T temporaryRezult = 0;
    for (int rowAndColumn = 0; rowAndColumn < firstMatrix.numberOfColumns; ++rowAndColumn) {
        temporaryRezult += (firstMatrix.getElement(tempMatrRow, rowAndColumn) * secondMatrix.getElement(rowAndColumn, tempMatrColumn));
    }

    return temporaryRezult;
}

template class BaseMatrix<double>;
template class BaseMatrix<int>; 
