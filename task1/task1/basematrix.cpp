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
    if (!fillingArray) {
        throw std::invalid_argument("invalid array");
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
    sourceCheck(source);

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
    sourceCheck(source);

    if (this == &source) {
        return *this;
    }

    freeMemory();

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
    freeMemory();
}

template <typename T>
std::unique_ptr<std::string> BaseMatrix<T>::matrixToString() { 
    std::unique_ptr<std::string> matrixInString = std::make_unique<std::string>();
    matrixInString->reserve( ((sizeof(T) * (this->getNumberOfRows() )) + (this->getNumberOfRows() + 1) ) * (this->getNumberOfColumns() ) );

    for (int indexOfRows = 0; indexOfRows < (this->getNumberOfRows() ); ++indexOfRows) {
        for (int indexOfColumns = 0; indexOfColumns < (this->getNumberOfColumns() ); ++indexOfColumns) {
            matrixInString->append(std::to_string(this->getElement(indexOfRows, indexOfColumns)));
            matrixInString->append(" ");
        }
        matrixInString->append("\n");
    }
    
    return matrixInString;
}
template <typename T>
T BaseMatrix<T>::getElement(int row, int column) const {
    rangeCheck(row, column, "out of range in getElement");
    
    return matrix[row][column];
}
template <typename T>
void BaseMatrix<T>::allocateMemory() {
    matrix = new T* [numberOfRows];
    for (int index = 0; index < numberOfRows; ++index) {
        matrix[index] = new T[numberOfColumns]{ T() };
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
    rangeCheck(row, column,"out of range in setElement");

    matrix[row][column] = element;
}

template <typename T>
std::unique_ptr<BaseMatrix<T>> BaseMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const {
    if (this->numberOfColumns != secondMatrix.numberOfRows) {
        throw std::invalid_argument("wrong size of matrices");
    }
    return this->multiplication(secondMatrix);
}

template <typename T>
std::unique_ptr<BaseMatrix<T>> BaseMatrix<T>::multiplication(const BaseMatrix<T>& secondMatrix) const{
    sourceCheck(secondMatrix);
    std::unique_ptr<BaseMatrix<T>> temporaryMatrix = std::make_unique<BaseMatrix<T>>(this->getNumberOfRows(), secondMatrix.getNumberOfColumns());

    for (int tempMatrRow = 0; tempMatrRow < temporaryMatrix->getNumberOfColumns(); ++tempMatrRow) {
        for (int tempMatrColumn = 0; tempMatrColumn < temporaryMatrix->numberOfRows; ++tempMatrColumn) {
            temporaryMatrix->setElement(secondMatrix.scalarMultiplication(*this, secondMatrix, tempMatrColumn, tempMatrRow), tempMatrRow, tempMatrColumn);
        }
    }
    return temporaryMatrix;
}

template <typename T>
T BaseMatrix<T>::scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColumn, int tempMatrRow) const {;
    T temporaryRezult = 0;
    for (int rowAndColumn = 0; rowAndColumn < firstMatrix.numberOfColumns; ++rowAndColumn) {
        temporaryRezult += (firstMatrix.getElement(tempMatrRow, rowAndColumn) * secondMatrix.getElement(rowAndColumn, tempMatrColumn));
    }
    return temporaryRezult;
}

template <typename T>
void BaseMatrix<T>::freeMemory() {
    if (matrix != nullptr) {
        for (int index = 0; index < numberOfRows; ++index) {
            delete[] matrix[index];
        }
        delete[] matrix;
    }
}

template <typename T>
void BaseMatrix<T>::rangeCheck(int row, int column, const char* message) const {
    if (((row < 0) || (row >= this->getNumberOfRows())) || (column < 0) || (column >= this->getNumberOfColumns())) {
        throw std::out_of_range(message);
    }
}

template <typename T>
void BaseMatrix<T>::sourceCheck(const BaseMatrix<T>& source) const {
    if (&source == NULL) {
        throw std::invalid_argument("invalid source");
    }
}

template class BaseMatrix<double>;
template class BaseMatrix<int>; 
