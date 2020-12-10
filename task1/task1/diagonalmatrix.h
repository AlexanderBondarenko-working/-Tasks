#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"

class DiagonalMatrix : public BaseMatrix {
	int sizeOfdiagonal;
	int* diagonalMatrix;
public:
	DiagonalMatrix();
	DiagonalMatrix(const int numberOflines, const int numberOfcolums);
	DiagonalMatrix(const int numberOflines, const int numberOfcolums, const int*
		fillingArray, const int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix& source);
	DiagonalMatrix& operator = (const DiagonalMatrix& source);
	~DiagonalMatrix();
	virtual int getElement(const int line, const int colum) const;
	//friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	virtual void out();
};
#endif  // TASK1_DIAGONALMATRIX_H_ 