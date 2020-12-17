#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 

#include "squarematrix.h"

template <class T>
class DiagonalMatrix : public SquareMatrix<T> {
protected:
	DiagonalMatrix();
	T scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int resIndexColumn, int resIndexRow) const;
public:
	DiagonalMatrix(int sizeOfMatrix);
	DiagonalMatrix(int sizeOfMatrix, const T*
		fillingArray, int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix<T>& source);
	~DiagonalMatrix();
	virtual T getElement(int row, int column) const;
	virtual void setElement(T element, int row, int column);
	BaseMatrix<T>* operator *(const BaseMatrix<T>& secondMatrix) const;
	virtual BaseMatrix<T>* multiplication(const BaseMatrix<T>& secondMatrix) const;
	virtual int getNumberOfRows() const;
	virtual int getNumberOfColumns() const;
};

#endif  // TASK1_DIAGONALMATRIX_H_ 