#ifndef TASK1_SQUAREMATRIX_H_ 
#define TASK1_SQUAREMATRIX_H_

#include "basematrix.h"

template <class T>
class SquareMatrix : public BaseMatrix<T> {
protected:
	SquareMatrix();
	SquareMatrix(int numberOfRows, int numberOfColumns); 
	SquareMatrix(int numberOfRows, int numberOfColumns, const T* fillingArray, int sizeOfarray);
public:
	SquareMatrix(int dimensionOfMatrix);
	SquareMatrix(int dimensionOfMatrix, const T* fillingArray, int sizeOfarray);
	SquareMatrix(const SquareMatrix<T>& source);
	virtual ~SquareMatrix();
	int getDimension();
};

#endif //TASK1_SQUAREMATRIX_H_