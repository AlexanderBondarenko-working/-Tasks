#include "squarematrix.h"

template <typename T>
SquareMatrix<T>::SquareMatrix() : BaseMatrix<T>::BaseMatrix() {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int numberOfRows, int numberOfColumns) : BaseMatrix<T>::BaseMatrix(numberOfRows, numberOfColumns) {};

template <typename T>
SquareMatrix<T>::SquareMatrix(int numberOfRows, int numberOfColumns, const T* fillingArray, int sizeOfarray) 
	: BaseMatrix<T>::BaseMatrix(numberOfRows, numberOfColumns, fillingArray, sizeOfarray) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int sizeOfMatrix) : BaseMatrix<T>::BaseMatrix(sizeOfMatrix, sizeOfMatrix) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int sizeOfMatrix, const T*
	fillingArray, int sizeOfarray) : BaseMatrix<T>::BaseMatrix(sizeOfMatrix, sizeOfMatrix, fillingArray, sizeOfarray) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& source) : BaseMatrix<T>::BaseMatrix(source) {}

template <typename T>
SquareMatrix<T>::~SquareMatrix() {}

template class SquareMatrix<int>;
template class SquareMatrix<double>;