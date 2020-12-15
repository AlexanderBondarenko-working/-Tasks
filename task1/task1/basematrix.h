#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class BaseMatrix {
	void allocateMemory();
protected:
	int numberOfRows;
	int numberOfColumns;
	T** matrix;
	BaseMatrix();
public:
	BaseMatrix(int numberOfRows, int numberOfColumns);
	BaseMatrix(int numberOfRows, int numberOfColumns, const T*
		       fillingArray, int sizeOfarray);
	BaseMatrix(const BaseMatrix<T>& source);
	virtual ~BaseMatrix();

	BaseMatrix<T>& operator = (const BaseMatrix<T>& source);
	virtual BaseMatrix<T>* operator *(const BaseMatrix<T>& secondMatrix) const;
	virtual T scalarMultiplication(const BaseMatrix<T>& firstMatrix,const BaseMatrix<T>& secondMatrix, int resIndexColumn, int resIndexRow) const;

	virtual std::string matrixToString();
	virtual T getElement(int row, int column) const;
	virtual BaseMatrix<T>* matrixMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix) const;

	int getNumberOfRows() const;
	int getNumberOfColumns() const;
	virtual void setElement(T element, int row, int column);
};


#endif  // TASK1_BASEMATRIX_H_ 

