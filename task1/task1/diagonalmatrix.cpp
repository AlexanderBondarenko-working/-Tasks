#include "diagonalmatrix.h"

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix() : BaseMatrix<T>::BaseMatrix() {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfColumns)
{
	this->numberOfRows = numberOfRows;
	this->numberOfColumns = numberOfColumns;
	allocateMemory();
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfColumns, const T*
	fillingArray, int sizeOfarray)
{
	if (numberOfColumns != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	this->numberOfRows = numberOfRows;
	this->numberOfColumns = numberOfColumns;
	allocateMemory();
	std::memcpy(this->matrix[0], fillingArray, (sizeof(T) * numberOfColumns));
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& source)
{
	if (source.matrix) {
		this->numberOfRows = source.numberOfRows;
		this->numberOfColumns = source.numberOfColumns;
		this->allocateMemory();
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * this->numberOfColumns));
	}
    else
		this->matrix = nullptr;
}

template <typename T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator = (const DiagonalMatrix<T>& source)
{

	if (this == &source) {
		return *this;
	}

    if (source.matrix) {
		delete[] this->matrix[0];
		delete[] this->matrix;
		this->allocateMemory();
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * (this->numberOfColumns)));
	}
	else {
		this->matrix = nullptr;
	}

	return *this;
}

template <typename T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
	delete[] this->matrix[0];
	delete[] this->matrix;
	this->matrix = nullptr;
}

template <typename T>
std::string DiagonalMatrix<T>::matrixToString() {
	std::string matrixInString;
	matrixInString.reserve(((sizeof(T) * (this->getNumberOfRows())) + (this->getNumberOfRows()) + 1) * (this->getNumberOfColumns()));

	for (int indexOfRows = 0; indexOfRows < this->getNumberOfRows(); ++indexOfRows) {
		for (int indexOfColumns = 0; indexOfColumns < this->getNumberOfColumns(); ++indexOfColumns) {
				matrixInString.append(std::to_string(this->getElement(indexOfRows, indexOfColumns)));
				matrixInString.append(" ");
		}
		matrixInString.append("\n");
	}

	return matrixInString;
}

template <typename T>
T DiagonalMatrix<T>::getElement(int row, int column) const {
	if ((row < 0) || (row >= this -> getNumberOfRows()) || (column < 0) || (column >= this -> getNumberOfColumns())) {
		throw std::out_of_range("out of range in getElement");
	}
	if (row == column) {
		return this->matrix[0][column];
	}

	return 0;
}

template <typename T>
void DiagonalMatrix<T>::allocateMemory() {
	this->matrix = new T* [1];
	this->matrix[0] = new T[(this->numberOfColumns)]{ 0 };
}

template <typename T>
void DiagonalMatrix<T>::setElement(T element, int row, int column) {
    if ((row < 0) || (row >= this->numberOfRows) || (column < 0) || (column >= this->numberOfColumns) || (row == column)) {
        throw std::out_of_range("out of range in getElement");
    }

    this->matrix[0][column] = element;
}

template <typename T>
BaseMatrix<T>* DiagonalMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const {
	if ((this->getNumberOfRows() != secondMatrix.getNumberOfColumns())
		&& (this->getNumberOfColumns() != secondMatrix.getNumberOfRows())) {
		throw std::invalid_argument("wrong size of matrices");
	}

	return this->matrixMultiplication(*this, secondMatrix);
}

template <typename T>
BaseMatrix<T>* DiagonalMatrix<T>::matrixMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix) const { 
	BaseMatrix<T>* temporaryMatrix = new BaseMatrix<T>((this->getNumberOfRows()), secondMatrix.getNumberOfColumns());

	for (int tempMatrRow = 0; tempMatrRow < firstMatrix.getNumberOfColumns(); ++tempMatrRow) {
		for (int tempMatrColumn = 0; tempMatrColumn < secondMatrix.getNumberOfColumns(); ++tempMatrColumn) {
			temporaryMatrix->setElement((firstMatrix.getElement(tempMatrRow, tempMatrRow)) * (secondMatrix.getElement(tempMatrRow, tempMatrColumn)), tempMatrRow, tempMatrColumn);
		}
	}
	return temporaryMatrix;
}

template <typename T>
T DiagonalMatrix<T>::scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColumn, int tempMatrRow) const {
	if (tempMatrColumn <= secondMatrix.getNumberOfRows()) {
		return (firstMatrix.getElement(tempMatrRow, tempMatrColumn)* secondMatrix.getElement(tempMatrColumn, tempMatrColumn));
	}
	return 0;
}

template class DiagonalMatrix<int>;
template class DiagonalMatrix<double>;