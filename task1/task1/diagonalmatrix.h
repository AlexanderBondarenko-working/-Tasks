#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"
//шаблон
class DiagonalMatrix : public BaseMatrix {
	int* diagonalMatrix;
protected:
	DiagonalMatrix();
	DiagonalMatrix(int numberOflines, int numberOfColums);
public:
	DiagonalMatrix(int numberOflines, int numberOfColums, const int*
		fillingArray, int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix& source);
	DiagonalMatrix& operator = (const DiagonalMatrix& source);
	~DiagonalMatrix();
	virtual int getElement(int row, int colum) const;
	virtual std::string matrixToString();
};
#endif  // TASK1_DIAGONALMATRIX_H_ 