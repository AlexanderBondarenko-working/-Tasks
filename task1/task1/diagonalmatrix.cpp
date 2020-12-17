#include "diagonalmatrix.h"
#include "basematrix.h"

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix() : SquareMatrix<T>::SquareMatrix() {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int dimensionOfMatrix) : SquareMatrix<T>::SquareMatrix(1, dimensionOfMatrix) {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int dimensionOfMatrix, const T*
	fillingArray, int sizeOfarray) : SquareMatrix<T>::SquareMatrix(1, dimensionOfMatrix, fillingArray, sizeOfarray) {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& source) : SquareMatrix<T>::SquareMatrix(source){}

template <typename T>
DiagonalMatrix<T>::~DiagonalMatrix(){}

template <typename T>
void DiagonalMatrix<T>::setElement(T element, int row, int column) {
	if (row != column) {
		throw std::out_of_range("out of diagonal");
	}
	if (((row < 0) || (row >= this->getNumberOfRows())) || ((column < 0) || (column >= this->getNumberOfColumns()))) {
		throw std::out_of_range("out of range");
	}
	this->SquareMatrix<T>::setElement(element, 0, column);
}

template <typename T>
std::unique_ptr<BaseMatrix<T>> DiagonalMatrix<T>::operator * (const BaseMatrix<T>& secondMatrix) const {
	if (this->getNumberOfColumns() != secondMatrix.getNumberOfRows()) {
		throw std::invalid_argument("wrong size of matrices");
	}
	return this->multiplication(secondMatrix);
}

template <typename T>
std::unique_ptr<BaseMatrix<T>> DiagonalMatrix<T>::multiplication(const BaseMatrix<T>& secondMatrix) const {
	this->sourceCheck(secondMatrix);
	std::unique_ptr<BaseMatrix<T>> temporaryMatrix = std::make_unique<BaseMatrix<T>>(this->getNumberOfRows(), secondMatrix.getNumberOfColumns());
	for (int tempMatrRow = 0; tempMatrRow < this->getNumberOfColumns(); ++tempMatrRow) {
		for (int tempMatrColumn = 0; tempMatrColumn < secondMatrix.getNumberOfColumns(); ++tempMatrColumn) {
			temporaryMatrix->setElement(((this->getElement(tempMatrRow, tempMatrRow)) * (secondMatrix.getElement(tempMatrRow, tempMatrColumn))), tempMatrRow, tempMatrColumn);
		}
	}
	return temporaryMatrix;
}

template <typename T>
T DiagonalMatrix<T>::scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int tempMatrColumn, int tempMatrRow) const {
	if (tempMatrColumn < secondMatrix.getNumberOfColumns()) {
		return (firstMatrix.getElement(tempMatrRow, tempMatrColumn)* secondMatrix.getElement(tempMatrColumn, tempMatrColumn));
	}
	return T();
}

template <typename T>
int DiagonalMatrix<T>::getNumberOfRows() const {
	return this->SquareMatrix<T>::getNumberOfColumns();
}

template <typename T>
int DiagonalMatrix<T>::getNumberOfColumns() const {
	return this->SquareMatrix<T>::getNumberOfColumns();
}

template <typename T>
T DiagonalMatrix<T>::getElement(int row, int column) const {
	this->rangeCheck(row, column, "out of range in getElement of DiagonalMatrix");
	if (row == column) {
		return this->SquareMatrix<T>::getElement(0, column);
	}

	return T();
}

template class DiagonalMatrix<int>;
template class DiagonalMatrix<double>;