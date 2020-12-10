#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
class BaseMatrix {
	int numberOfRows; 
	int numberOfColums;
	int** matrix;
	void initMatrix();
protected:
	BaseMatrix();
	BaseMatrix(const int numberOfRows, const int numberOfColums);
public:
	BaseMatrix(const int numberOfRows, const int numberOfColums, const int*
		       fillingArray, const int sizeOfarray);
	BaseMatrix(const BaseMatrix& source);
	virtual int getElement(const int line, const int colum) const;
	BaseMatrix& operator = (const BaseMatrix& source);
	virtual ~BaseMatrix();
	friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	virtual void out();
	int getNumberOfRows() const;
	int getnumberOfColums() const;
};

#endif  // TASK1_BASEMATRIX_H_ 