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
	int numberOfcolumns;
	T** matrix;
	BaseMatrix();
public:
	BaseMatrix(int numberOfRows, int numberOfcolumns);
	BaseMatrix(int numberOfRows, int numberOfcolumns, const T*
		       fillingArray, int sizeOfarray);
	BaseMatrix(const BaseMatrix<T>& source);
	virtual ~BaseMatrix();

	BaseMatrix<T>& operator = (const BaseMatrix<T>& source);
	BaseMatrix<T> operator *(const BaseMatrix<T>& secondMatrix) const;
	T scalarMultiplication(const BaseMatrix<T>& secondMatrix, int resIndexcolumn, int resIndexline) const;

	virtual std::string matrixToString();
	virtual T getElement(int row, int column) const;


	int getNumberOfRows() const;
	int getNumberOfcolumns() const;
	virtual void setElement(T element, int row, int column);
};


#endif  // TASK1_BASEMATRIX_H_ 

