#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"

class DiagonalMatrix : public BaseMatrix {
	int* diagonalMatrix;
public:
	DiagonalMatrix();
	DiagonalMatrix(const int numberOflines, const int numberOfcolums);
	DiagonalMatrix(const int numberOflines, const int numberOfcolums, const int*
		fillingArray, const int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix& source);
	DiagonalMatrix& operator = (const DiagonalMatrix& source);
	~DiagonalMatrix();
	//friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	void out();
};
#endif  // TASK1_DIAGONALMATRIX_H_ 