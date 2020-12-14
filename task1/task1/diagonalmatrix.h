#ifndef TASK1_DIAGONALMATRIX_H_ 
#define TASK1_DIAGONALMATRIX_H_ 
#include "basematrix.h"

template <class T>
class DiagonalMatrix : public BaseMatrix<T> {
	T* diagonalMatrix;
protected:
	DiagonalMatrix();
	DiagonalMatrix(int numberOflines, int numberOfColums);
public:
	DiagonalMatrix(int numberOflines, int numberOfColums, const T*
		fillingArray, int sizeOfarray);
	DiagonalMatrix(const DiagonalMatrix<T>& source);
	DiagonalMatrix<T>& operator = (const DiagonalMatrix<T>& source);
	~DiagonalMatrix();
	virtual T getElement(int row, int colum) const;
	virtual std::string matrixToString();
};

#endif  // TASK1_DIAGONALMATRIX_H_ 