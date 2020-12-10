#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
class BaseMatrix {
	int numberOflines;
	int numberOfcolums;
	int** matrix;
public:
	BaseMatrix();
	BaseMatrix(const int numberOflines, const int numberOfcolums);
	BaseMatrix(const int numberOflines, const int numberOfcolums, const int*
		       fillingArray, const int sizeOfarray);
	BaseMatrix(const BaseMatrix& source);
	BaseMatrix& operator = (const BaseMatrix& source);
	virtual ~BaseMatrix();
	friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	void out();
	virtual int getElement(const int line, const int colum);
};

#endif  // TASK1_BASEMATRIX_H_ 