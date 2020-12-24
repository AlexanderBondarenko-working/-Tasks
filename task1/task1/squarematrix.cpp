#include "squarematrix.h"

template <typename T>
SquareMatrix<T>::SquareMatrix() : BaseMatrix<T>::BaseMatrix() {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int numberOfRows, int numberOfColumns) : BaseMatrix<T>::BaseMatrix(numberOfRows, numberOfColumns) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int numberOfRows, int numberOfColumns, const T* fillingArray, int sizeOfarray) 
	: BaseMatrix<T>::BaseMatrix(numberOfRows, numberOfColumns, fillingArray, sizeOfarray) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int dimensionOfMatrix) : BaseMatrix<T>::BaseMatrix(dimensionOfMatrix, dimensionOfMatrix) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(int dimensionOfMatrix, const T*
	fillingArray, int sizeOfarray) : BaseMatrix<T>::BaseMatrix(dimensionOfMatrix, dimensionOfMatrix, fillingArray, sizeOfarray) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& source) : BaseMatrix<T>::BaseMatrix(source) {}

template <typename T>
SquareMatrix<T>::~SquareMatrix() {}

template <typename T>
int SquareMatrix<T>::getDimension() {
	return this->getNumberOfColumns();
}

template class SquareMatrix<int>;
template class SquareMatrix<double>;