#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
#include <string>
//template
class BaseMatrix {
	int numberOfRows; 
	int numberOfColums;
	int** matrix;
	void allocateMemory();
protected:
	BaseMatrix();
	BaseMatrix(int numberOfRows, int numberOfColums);
public:
	BaseMatrix(int numberOfRows, int numberOfColums, const int*
		       fillingArray, int sizeOfarray);
	BaseMatrix(const BaseMatrix& source);
	virtual int getElement(int row, int colum) const;
	BaseMatrix& operator = (const BaseMatrix& source);
	virtual ~BaseMatrix();
	friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	friend int scalarMultiplication(const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix, int resIndexColum, int resIndexline);
	virtual std::string matrixToString();
	int getNumberOfRows() const;
	int getNumberOfColums() const;
};

#endif  // TASK1_BASEMATRIX_H_ 