#include "diagonalmatrix.h"

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix() : BaseMatrix<T>::BaseMatrix(), diagonalMatrix(nullptr) {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOflines, int numberOfColums) 
    : BaseMatrix<T>::BaseMatrix(numberOflines, numberOfColums), diagonalMatrix(nullptr) {}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int numberOflines, int numberOfColums, const T*
	fillingArray, int sizeOfarray) : BaseMatrix<T>::BaseMatrix(numberOflines, numberOfColums)
{
	if (numberOfColums != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	diagonalMatrix = new T[this -> getNumberOfColums()];

	std::memcpy(diagonalMatrix, fillingArray, (sizeof(T) * numberOfColums));
}

template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& source) : BaseMatrix<T>::BaseMatrix(source)
{
	if (source.diagonalMatrix) {
		diagonalMatrix = new T[source.getNumberOfColums()];
		std::memcpy(diagonalMatrix, source.diagonalMatrix, (sizeof(T) * this -> getNumberOfColums()));
	}
    else
		diagonalMatrix = nullptr;
}

template <typename T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator = (const DiagonalMatrix<T>& source)
{

	if (this == &source) {
		return *this;
	}

	if (diagonalMatrix != nullptr) {
		delete[] diagonalMatrix;
	}

	*this = source;

    if (source.diagonalMatrix) {
		diagonalMatrix = new T[this -> getNumberOfColums()];
		std::memcpy(diagonalMatrix, source.diagonalMatrix, (sizeof(T) * this -> getNumberOfColums()));
	}
	else {
		diagonalMatrix = nullptr;
	}

	return *this;
}

template <typename T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
	delete[] diagonalMatrix;
}

template <typename T>
std::string DiagonalMatrix<T>::matrixToString() {
	std::string matrixInString;
	matrixInString.reserve(((sizeof(T) * (this->getNumberOfRows())) + (this->getNumberOfRows()) + 1) * (this->getNumberOfColums()));

	for (int indexOflines = 0; indexOflines < this->getNumberOfRows(); ++indexOflines) {
		for (int indexOfcolums = 0; indexOfcolums < this->getNumberOfColums(); ++indexOfcolums) {
			if (indexOflines == indexOfcolums) {
				matrixInString.append(std::to_string(diagonalMatrix[indexOfcolums]));
				matrixInString.append(" ");
			}
			else {
				matrixInString.append("0");
				matrixInString.append(" ");
			}
		}
		matrixInString.append("\n");
	}

	return matrixInString;
}

template <typename T>
T DiagonalMatrix<T>::getElement(int row, int colum) const {
	if (((row < 0) || (row >= this -> getNumberOfRows()) || ((colum < 0) || (colum >= this -> getNumberOfColums())))) {
		throw std::out_of_range("out of range in getElement");
	}
	if (row == colum) {
		return diagonalMatrix[colum];
	}

	return 0;
}

template class DiagonalMatrix<int>;
template class DiagonalMatrix<double>;