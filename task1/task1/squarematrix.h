#ifndef TASK1_SQUAREMATRIX_H_ 
#define TASK1_SQUAREMATRIX_H_

#include "basematrix.h"

template <class T>
class SquareMatrix : public BaseMatrix<T> {
protected:
	SquareMatrix();
public:
	SquareMatrix(int sizeOfMatrix);
	SquareMatrix(int sizeOfMatrix, const T*
		fillingArray, int sizeOfarray);
	SquareMatrix(const SquareMatrix<T>& source);
	virtual ~SquareMatrix();
};

#endif //TASK1_SQUAREMATRIX_H_