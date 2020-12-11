#include "diagonalmatrix.h"


DiagonalMatrix::DiagonalMatrix() : BaseMatrix(), diagonalMatrix(nullptr) {}

DiagonalMatrix::DiagonalMatrix(int numberOflines, int numberOfColums) 
    : BaseMatrix(numberOflines, numberOfColums), diagonalMatrix(nullptr) {}

DiagonalMatrix::DiagonalMatrix(int numberOflines, int numberOfColums, const int*
	fillingArray, int sizeOfarray) : BaseMatrix(numberOflines, numberOfColums)
{
	if (numberOfColums != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	diagonalMatrix = new int[getNumberOfColums()];

	std::memcpy(diagonalMatrix, fillingArray, (sizeof(int) * numberOfColums));
}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& source) : BaseMatrix(source)
{
	if (source.diagonalMatrix) {
		diagonalMatrix = new int[source.getNumberOfColums()];
		std::memcpy(diagonalMatrix, source.diagonalMatrix, (sizeof(int) * getNumberOfColums()));
	}
    else
		diagonalMatrix = nullptr;
}

DiagonalMatrix& DiagonalMatrix::operator = (const DiagonalMatrix& source)
{

	if (this == &source) {
		return *this;
	}

	if (diagonalMatrix != nullptr) {
		delete[] diagonalMatrix;
	}

	*this = source;

    if (source.diagonalMatrix) {
		diagonalMatrix = new int[getNumberOfColums()];
		std::memcpy(diagonalMatrix, source.diagonalMatrix, (sizeof(int) * getNumberOfColums()));
	}
	else {
		diagonalMatrix = nullptr;
	}

	return *this;
}

DiagonalMatrix::~DiagonalMatrix()
{
	delete[] diagonalMatrix;
}

std::string DiagonalMatrix::matrixToString() {
	std::string matrixInString;
	matrixInString.reserve(((sizeof(int) * (this->getNumberOfRows())) + (this->getNumberOfRows()) + 1) * (this->getNumberOfColums()));

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

int DiagonalMatrix::getElement(int row, int colum) const {
	if (((row <= 0) || (row >= this -> getNumberOfRows()) || ((colum <= 0) || (colum >= this -> getNumberOfColums())))) {
		throw std::out_of_range("out of range in getElement");
	}
	if (row == colum) {
		return diagonalMatrix[colum];
	}

	return 0;
}