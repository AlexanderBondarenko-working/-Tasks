﻿#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"
//шаблон
class DiagonalMatrix : public BaseMatrix {
	int sizeOfdiagonal; //возможно лишняя
	int* diagonalMatrix;
public:
	DiagonalMatrix();
	DiagonalMatrix(int numberOflines, int numberOfColums); // const перебор не надо
	DiagonalMatrix(int numberOflines, int numberOfColums, const int*
		fillingArray, const int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix& source);
	DiagonalMatrix& operator = (const DiagonalMatrix& source);
	~DiagonalMatrix();
	virtual int getElement(int line, int colum) const;
	//friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	virtual void out();
};
#endif  // TASK1_DIAGONALMATRIX_H_ 