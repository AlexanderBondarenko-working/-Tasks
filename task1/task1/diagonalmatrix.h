#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"

template <class T>
class DiagonalMatrix : public BaseMatrix<T> {
	void allocateMemory();
	int sizeOfDiagonal;
	void init(int numberOfRows, int numberOfColumns);
	void deleteMemory();
protected:
	DiagonalMatrix();
	T scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int resIndexColumn, int resIndexRow) const;
public:
	DiagonalMatrix(int numberOfRows, int numberOfColumns);
	DiagonalMatrix(int numberOfRows, int numberOfColumns, const T*
		fillingArray, int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix<T>& source);
	DiagonalMatrix<T>& operator = (const DiagonalMatrix<T>& source);
	~DiagonalMatrix();
	virtual T getElement(int row, int column) const;
	virtual void setElement(T element, int row, int column);

	int getSizeOfDiagonal() const;
	BaseMatrix<T>* operator *(const BaseMatrix<T>& secondMatrix) const;
	virtual BaseMatrix<T>* multiplication(const BaseMatrix<T>& secondMatrix) const;
};

#endif  // TASK1_DIAGONALMATRIX_H_ 