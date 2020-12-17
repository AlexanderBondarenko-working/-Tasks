#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

#include <iostream>
#include <stdexcept>
#include <string>

//!  A BaseMatrix class. 
/*!
  This class can store matrices of different dimensions and allows you to multiply them together.
*/

template <class T>
class BaseMatrix {
	void allocateMemory();
	void freeMemory();
	int numberOfRows;
	int numberOfColumns;
	T** matrix;
	BaseMatrix<T>& operator = (const BaseMatrix<T>& source);
protected:
	BaseMatrix();
	virtual T scalarMultiplication(const BaseMatrix<T>& firstMatrix, const BaseMatrix<T>& secondMatrix, int resIndexColumn, int resIndexRow) const;
	void rangeCheck(int row, int column, const char* message) const;
	void sourceCheck(const BaseMatrix<T>& source) const;
public:
	//! A constructor with parameters.
	/*!
	  This constructor fills the fields with parameters, 
	  allocates memory for the matrix and fills it with zeros of the template data type.
	*/
	BaseMatrix(int numberOfRows, int numberOfColumns);
	//! A constructor with parameters.
	/*!
	  This constructor fills the fields with parameters, 
	  allocates memory for the matrix and fills with values ??from the passed array.
	*/
	BaseMatrix(int numberOfRows, int numberOfColumns, const T*
		       fillingArray, int sizeOfarray);
	//! A copy constructor.
	/*!
	  This constructor does deep copy.
	*/
	BaseMatrix(const BaseMatrix<T>& source);
	//! A destructor.
	/*!
	  Frees the memory allocated for the matrix.
	*/
	virtual ~BaseMatrix();
	//! A matrix multiplication operator.
	/*!
    A operator of multiplying the base matrix by the one on the right, 
    returns a smart pointer to the matrix containing the result.
	*/
	virtual std::unique_ptr<BaseMatrix<T>> operator *(const BaseMatrix<T>& secondMatrix) const;
	//! A matrixToString method.
	/*!
	A method returns a smart pointer to the contents of the 
	matrix as a delimited string with hyphenation characters.
	*/
	std::unique_ptr<std::string> matrixToString();
	//! A getElement method.
	/*!
	A method returns a copy of the matrix element located in row number "row" 
	and column number "column". If the matrix is ??exceeded, an exception will be thrown.
	*/
	virtual T getElement(int row, int column) const;
	//! A multiplication method.
	/*!
	The method returns the matrix resulting from the multiplication of the caller's matrix by the parameter's object matrix
	*/
	std::unique_ptr<BaseMatrix<T>> multiplication(const BaseMatrix<T>& secondMatrix) const;
	//! A getNumberOfRows method.
	/*!
	A method returns a copy of the number of rows.
	*/
	virtual int getNumberOfRows() const;
	//! A getNumberOfColumns method.
	/*!
	A method returns a copy of the number of columns.
	*/
	virtual int getNumberOfColumns() const;
	//! A setElement method.
	/*!
	The method sets the element in row "row" and column "column" equal to "element". 
	If the matrix is ??exceeded, an exception will be thrown.
	*/
	virtual void setElement(T element, int row, int column);
};


#endif  // TASK1_BASEMATRIX_H_ 

