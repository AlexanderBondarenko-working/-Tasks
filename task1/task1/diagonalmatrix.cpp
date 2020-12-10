#include "diagonalmatrix.h"


DiagonalMatrix::DiagonalMatrix() : BaseMatrix(), sizeOfdiagonal(0), diagonalMatrix(nullptr) {}

DiagonalMatrix::DiagonalMatrix(const int numberOflines, const int numberOfcolums) 
    : BaseMatrix(numberOflines, numberOfcolums), diagonalMatrix(nullptr), sizeOfdiagonal(numberOfcolums) {}

DiagonalMatrix::DiagonalMatrix(const int numberOflines, const int numberOfcolums, const int*
	fillingArray, const int sizeOfarray) : BaseMatrix(numberOflines, numberOfcolums), sizeOfdiagonal(sizeOfarray)
{
	if (numberOfcolums != sizeOfarray) {
		throw std::invalid_argument("invalid array length");
	}

	diagonalMatrix = new int[sizeOfdiagonal];

	for (int index = 0; index < sizeOfdiagonal; ++index) {
		diagonalMatrix[index] = fillingArray[index];
	}
}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& source) : BaseMatrix(source), sizeOfdiagonal(source.sizeOfdiagonal)
{
	if (source.diagonalMatrix) {
		diagonalMatrix = new int[source.sizeOfdiagonal];

		for (int index = 0; index < sizeOfdiagonal; ++index) {
			diagonalMatrix[index] = source.diagonalMatrix[index];
		}
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
		diagonalMatrix = new int[sizeOfdiagonal];
		for (int index = 0; index < sizeOfdiagonal; ++index) {
			diagonalMatrix[index] = source.diagonalMatrix[index];
		}
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

void DiagonalMatrix::out() {
	for (int indexOflines = 0; indexOflines < this -> getNumberOflines(); ++indexOflines) {
		for (int indexOfcolums = 0; indexOfcolums < this -> getNumberOflines(); ++indexOfcolums) {
			if (indexOflines == indexOfcolums) {
				std::cout << diagonalMatrix[indexOfcolums] << " ";
			}
			else {
				std::cout << 0 << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

int DiagonalMatrix::getElement(const int line, const int colum) const {

	if (line == colum) {
		return diagonalMatrix[colum];
	}

	return 0;
}