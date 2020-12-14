#include "diagonalmatrix.h"

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix() : BaseMatrix<T>::BaseMatrix(){} //?????

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfcolumns)
{
	this->numberOfRows = numberOfRows;
	this->numberOfcolumns = numberOfcolumns;
	allocateMemory();
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOfRows, int numberOfcolumns, const T*
	fillingArray, int sizeOfarray)
{
	if (numberOfcolumns != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	this->numberOfRows = numberOfRows;
	this->numberOfcolumns = numberOfcolumns;
	allocateMemory();
	std::memcpy(this->matrix[0], fillingArray, (sizeof(T) * numberOfcolumns));
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& source)
{
	if (source.matrix) {
		this->numberOfRows = source.numberOfRows;
		this->numberOfcolumns = source.numberOfcolumns;
		this->allocateMemory();
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * this->numberOfcolumns));
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
		std::memcpy(this->matrix[0], source.matrix[0], (sizeof(T) * this->numberOfcolumns));
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
	matrixInString.reserve(((sizeof(T) * (this->getNumberOfRows())) + (this->getNumberOfRows()) + 1) * (this->getNumberOfcolumns()));

	for (int indexOfRows = 0; indexOfRows < this->getNumberOfRows(); ++indexOfRows) {
		for (int indexOfcolumns = 0; indexOfcolumns < this->getNumberOfcolumns(); ++indexOfcolumns) {
				matrixInString.append(std::to_string(this->getElement(indexOfRows, indexOfcolumns)));
				matrixInString.append(" ");
		}
		matrixInString.append("\n");
	}

	return matrixInString;
}

template <typename T>
T DiagonalMatrix<T>::getElement(int row, int column) const {
	if (((row < 0) || (row >= this -> getNumberOfRows()) || ((column < 0) || (column >= this -> getNumberOfcolumns())))) {
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
	this->matrix[0] = new T[this->numberOfcolumns]{ 0 };
}

template <typename T>
void DiagonalMatrix<T>::setElement(T element, int row, int column) {
    if (((row < 0) || (row >= this->numberOfRows)) || ((column < 0) || (column >= this->numberOfcolumns)) || (row == column)) {
        throw std::out_of_range("out of range in getElement");
    }

    this->matrix[0][column] = element;
}

template class DiagonalMatrix<int>;
template class DiagonalMatrix<double>;