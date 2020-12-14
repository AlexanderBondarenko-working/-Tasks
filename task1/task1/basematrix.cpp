 #include "basematrix.h"
 #include <cstring>

 template <typename T>
 BaseMatrix<T>::BaseMatrix() : numberOfRows(0), numberOfcolumns(0), matrix(nullptr) {}

 template <typename T>
 BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfcolumns)
    : numberOfRows(numberOfRows), numberOfcolumns(numberOfcolumns)
 {
     allocateMemory();
 }

template <typename T>
BaseMatrix<T>::BaseMatrix(int numberOfRows, int numberOfcolumns,
    const T* fillingArray, int sizeOfarray)
    : numberOfRows(numberOfRows), numberOfcolumns(numberOfcolumns)
{
    if ((numberOfRows * numberOfcolumns) != sizeOfarray) {
        throw std::invalid_argument("invalid array length");
    }

    this -> allocateMemory();

    for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
        for (int indexOfcolumns = 0; indexOfcolumns < numberOfcolumns; ++indexOfcolumns) {
            matrix[indexOfRows][indexOfcolumns] = fillingArray[((numberOfcolumns * indexOfRows) + indexOfcolumns)];
        }
    }
}
template <typename T>
BaseMatrix<T>::BaseMatrix(const BaseMatrix<T>& source)
{
    numberOfRows = source.numberOfRows;
    numberOfcolumns = source.numberOfcolumns;
    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
            std::memcpy(matrix[indexOfRows], source.matrix[indexOfRows], (sizeof(T) * numberOfcolumns));
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
    numberOfcolumns = source.numberOfcolumns;

    if (source.matrix) {
        this -> allocateMemory();
        for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
            std::memcpy(matrix[indexOfRows], source.matrix[indexOfRows], (sizeof(T) * numberOfcolumns));
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
T BaseMatrix<T>::scalarMultiplication(const BaseMatrix<T>& secondMatrix, int tempMatrcolumn, int tempMatrRow) const{

    T temporaryRezult = 0;
    for (int rowAndcolumn = 0; rowAndcolumn < this->numberOfcolumns; ++rowAndcolumn) {
        temporaryRezult += (this->getElement(tempMatrRow, rowAndcolumn) * secondMatrix.getElement(rowAndcolumn, tempMatrcolumn));
    }

    return temporaryRezult;
}
template <typename T>
BaseMatrix<T> BaseMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const{
    
    if ((this -> numberOfRows != secondMatrix.numberOfcolumns) 
        && (this-> numberOfcolumns != secondMatrix.numberOfRows)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    BaseMatrix<T> temporaryMatrix(this-> numberOfRows, secondMatrix.numberOfcolumns);
    temporaryMatrix.allocateMemory(); // в динамическое выделение

    for (int tempMatrRow = 0; tempMatrRow < temporaryMatrix.numberOfcolumns; ++tempMatrRow) {
        for (int tempMatrcolumn = 0; tempMatrcolumn < temporaryMatrix.numberOfRows; ++tempMatrcolumn) {
            temporaryMatrix.matrix[tempMatrRow][tempMatrcolumn] = scalarMultiplication(secondMatrix, tempMatrcolumn, tempMatrRow);
        }
    }
    return temporaryMatrix;
}

template <typename T>
std::string BaseMatrix<T>::matrixToString() {
    std::string matrixInString;
    matrixInString.reserve(((sizeof(T) * numberOfRows) + numberOfRows + 1) * numberOfcolumns);

    for (int indexOfRows = 0; indexOfRows < numberOfRows; ++indexOfRows) {
        for (int indexOfcolumns = 0; indexOfcolumns < numberOfcolumns; ++indexOfcolumns) {
            matrixInString.append(std::to_string(matrix[indexOfRows][indexOfcolumns]));
            matrixInString.append(" ");
        }
        matrixInString.append("\n");
    }
    
    return matrixInString;
}
template <typename T>
T BaseMatrix<T>::getElement(int row, int column) const {
    if (((row < 0) || (row >= numberOfRows)) || ((column < 0) || (column >= numberOfcolumns))) {
        throw std::out_of_range("out of range in getElement");
    }
    
    return matrix[row][column];
}
template <typename T>
void BaseMatrix<T>::allocateMemory() {
    matrix = new T* [numberOfRows];
    for (int index = 0; index < numberOfRows; ++index) {
        matrix[index] = new T[numberOfcolumns]{ 0 };
    }
}
template <typename T>
int BaseMatrix<T>::getNumberOfRows() const {
    return numberOfRows;
}
template <typename T>
int BaseMatrix<T>::getNumberOfcolumns() const {
    return numberOfcolumns;
}

template <typename T>
void BaseMatrix<T>::setElement(T element, int row, int column) {
    if (((row < 0) || (row >= numberOfRows)) || ((column < 0) || (column >= numberOfcolumns))) {
        throw std::out_of_range("out of range in getElement");
    }

    matrix[row][column] = element;
}

template class BaseMatrix<double>;
template class BaseMatrix<int>; 
