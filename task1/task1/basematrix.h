#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
class BaseMatrix {
	int numberOflines;
	int numberOfcolums;
	int** matrix;
	void initMatrix();
public:
	BaseMatrix();
	BaseMatrix(const int numberOflines, const int numberOfcolums);
	BaseMatrix(const int numberOflines, const int numberOfcolums, const int*
		       fillingArray, const int sizeOfarray);
	BaseMatrix(const BaseMatrix& source);
	virtual int getElement(const int line, const int colum) const;
	BaseMatrix& operator = (const BaseMatrix& source);
	virtual ~BaseMatrix();
	friend BaseMatrix operator * (const BaseMatrix& firstMatrix, const BaseMatrix& secondMatrix);
	virtual void out();
	int getNumberOflines() const;
	int getNumberOfcolums() const;
};

#endif  // TASK1_BASEMATRIX_H_ 