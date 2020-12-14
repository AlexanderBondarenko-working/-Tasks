#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class BaseMatrix {
	int numberOfRows; 
	int numberOfColums;
	T** matrix;
	void allocateMemory();
protected:
	BaseMatrix();
	BaseMatrix(int numberOfRows, int numberOfColums);
public:
	BaseMatrix(int numberOfRows, int numberOfColums, const T*
		       fillingArray, int sizeOfarray);
	BaseMatrix(const BaseMatrix<T>& source);
	virtual T getElement(int row, int colum) const;
	BaseMatrix<T>& operator = (const BaseMatrix<T>& source);
	virtual ~BaseMatrix();

	BaseMatrix<T> operator *(const BaseMatrix<T>& secondMatrix) const;
	template <class T>
	friend T scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int resIndexColum, int resIndexline);

	virtual std::string matrixToString();
	int getNumberOfRows() const;
	int getNumberOfColums() const;
};


#endif  // TASK1_BASEMATRIX_H_ 

