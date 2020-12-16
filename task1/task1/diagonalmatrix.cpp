#include "diagonalmatrix.h"

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix() : BaseMatrix<T>::BaseMatrix() {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfColumns)
{
	this->init(numberOfRows, numberOfColumns);
	allocateMemory();
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfColumns, const T*
	fillingArray, int sizeOfarray)
{
	this->init(numberOfRows, numberOfColumns);
	if (sizeOfDiagonal != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	if (!fillingArray) {
		throw std::invalid_argument("invalid array");
	}

	allocateMemory();
	std::memcpy(this->matrix[0], fillingArray, (sizeof(T) * numberOfColumns));
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& source)
{
	this->sourceCheck(source);

	if (source.matrix) {
		this->init(source.numberOfRows, source.numberOfColumns);
		this->allocateMemory();
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * this->sizeOfDiagonal));
	}
    else
		this->matrix = nullptr;
}

template <typename T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator = (const DiagonalMatrix<T>& source)
{
	this->sourceCheck(source);

	if (this == &source) {
		return *this;
	}

    if (source.matrix) {
		deleteMemory();
		this->allocateMemory();
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * (this->sizeOfDiagonal)));
	}
	else {
		this->matrix = nullptr;
	}

	return *this;
}

template <typename T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
	deleteMemory();
	this->matrix = nullptr;
}

template <typename T>
T DiagonalMatrix<T>::getElement(int row, int column) const {
	this->rangeCheck(row, column, "out of range in getElement of DiagonalMatrix");
	if (row == column) {
		return this->matrix[0][column];
	}

	return T();
}

template <typename T>
void DiagonalMatrix<T>::allocateMemory() {
	this->matrix = new T* [1];
	this->matrix[0] = new T[(this->numberOfColumns)]{ T() };
}

template <typename T>
void DiagonalMatrix<T>::setElement(T element, int row, int column) {
	this->rangeCheck(row, column, "out of range in setElement");

    this->matrix[0][column] = element;
}

template <typename T>
BaseMatrix<T>* DiagonalMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const {
	if ((this->getNumberOfRows() != secondMatrix.getNumberOfColumns())
		|| (this->getNumberOfColumns() != secondMatrix.getNumberOfRows())) {
		throw std::invalid_argument("wrong size of matrices");
	}
	return this->multiplication(secondMatrix);
}

template <typename T>
BaseMatrix<T>* DiagonalMatrix<T>::multiplication(const BaseMatrix<T>& secondMatrix) const { 
	this->sourceCheck(secondMatrix);
	BaseMatrix<T>* temporaryMatrix = new BaseMatrix<T>((this->getNumberOfRows()), secondMatrix.getNumberOfColumns());
	for (int tempMatrRow = 0; tempMatrRow < this->getSizeOfDiagonal(); ++tempMatrRow) {
		for (int tempMatrColumn = 0; tempMatrColumn < secondMatrix.getNumberOfColumns(); ++tempMatrColumn) {
			temporaryMatrix->setElement(((this->getElement(tempMatrRow, tempMatrRow)) * (secondMatrix.getElement(tempMatrRow, tempMatrColumn))), tempMatrRow, tempMatrColumn);
		}
	}
	return temporaryMatrix;
}

template <typename T>
T DiagonalMatrix<T>::scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColumn, int tempMatrRow) const {
	if (tempMatrColumn < std::min(secondMatrix.getNumberOfColumns(), secondMatrix.getNumberOfRows())) {
		return (firstMatrix.getElement(tempMatrRow, tempMatrColumn)* secondMatrix.getElement(tempMatrColumn, tempMatrColumn));
	}
	return T();
}

template <typename T>
void DiagonalMatrix<T>::init(int numberOfRows, int numberOfColumns) {
	this->numberOfRows = numberOfRows;
	this->numberOfColumns = numberOfColumns;
	this->sizeOfDiagonal = std::min(numberOfRows, numberOfColumns);
}

template <typename T>
void DiagonalMatrix<T>::deleteMemory() {
	delete[] this->matrix[0];
	delete[] this->matrix;
}

template <typename T>
int DiagonalMatrix<T>::getSizeOfDiagonal() const {
	return sizeOfDiagonal;
}

template class DiagonalMatrix<int>;
template class DiagonalMatrix<double>;