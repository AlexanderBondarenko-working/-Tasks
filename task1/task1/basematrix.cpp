 #include "basematrix.h"
 BaseMatrix::BaseMatrix() : numberOfRows(0), numberOfColums(0), matrix(nullptr) {}

 BaseMatrix::BaseMatrix(const int numberOfRows, const int numberOfColums) 
    : numberOfRows(numberOfRows), numberOfColums(numberOfColums), matrix(nullptr) {}

BaseMatrix::BaseMatrix(const int numberOfRows, const int numberOfColums,
    const int* fillingArray, const int sizeOfarray)
    : numberOfRows(numberOfRows), numberOfColums(numberOfColums)
{
    if ((numberOfRows * numberOfColums) != sizeOfarray) {
        throw std::invalid_argument("invalid array length");
    }

    this -> initMatrix();

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
        this -> initMatrix();
        for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
            for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
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
        for (int index = 0; index < numberOfRows; ++index) {
            delete[] matrix[index];
        }
    }
    delete[] matrix;

    numberOfRows = source.numberOfRows;
    numberOfColums = source.numberOfColums;

    if (source.matrix) {
        this -> initMatrix();
        for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
            for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
                matrix[indexOflines][indexOfcolums] = source.matrix[indexOflines][indexOfcolums];
            }
        } // копировать блоком memcpi
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

BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix) {
    if ((firstMatrix.numberOfRows != secondMatrix.numberOfColums) 
        && (firstMatrix.numberOfColums != secondMatrix.numberOfRows)) {
        throw std::invalid_argument("wrong size of matrices");
    }

    BaseMatrix temporaryMatrix(firstMatrix.numberOfRows, secondMatrix.numberOfColums);
    temporaryMatrix.initMatrix(); // в динамическое выделение
    int temporaryRezult; 

    for (int resIndexline = 0; resIndexline < temporaryMatrix.numberOfColums; ++resIndexline) { // может отдельный метод . сократьть кол-во циклов
        for (int resIndexColum = 0; resIndexColum < temporaryMatrix.numberOfRows; ++resIndexColum) {
            temporaryRezult = 0;
            for (int lineAndColum = 0; lineAndColum < firstMatrix.numberOfColums; ++lineAndColum) {
                temporaryRezult += (firstMatrix.getElement(resIndexline, lineAndColum) * secondMatrix.getElement(lineAndColum, resIndexColum));
            }
            temporaryMatrix.matrix[resIndexline][resIndexColum] = temporaryRezult;
        }
    }
    return temporaryMatrix;
}

void BaseMatrix::out() { // matrixToString
    for (int indexOflines = 0; indexOflines < numberOfRows; ++indexOflines) {
        for (int indexOfcolums = 0; indexOfcolums < numberOfColums; ++indexOfcolums) {
            std::cout << matrix[indexOflines][indexOfcolums] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int BaseMatrix::getElement(const int line, const int colum) const { // проверка на выход за пределы
    
    return matrix[line][colum];
}

void BaseMatrix::initMatrix() { //название allocate memory
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