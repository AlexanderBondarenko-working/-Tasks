#include "diagonalmatrix.h"


DiagonalMatrix::DiagonalMatrix() : BaseMatrix() {}

DiagonalMatrix::DiagonalMatrix(const int numberOflines, const int numberOfcolums) 
{

}

DiagonalMatrix::DiagonalMatrix(const int numberOflines, const int numberOfcolums, const int*
	fillingArray, const int sizeOfarray)
{

}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& source) 
{

}

DiagonalMatrix& DiagonalMatrix::operator = (const DiagonalMatrix& source)
{
	return *this;
}

DiagonalMatrix::~DiagonalMatrix()
{

}
//friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
void out();