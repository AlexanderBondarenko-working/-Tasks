#include <exception>
#include "basematrix.h"
#include "diagonalmatrix.h"
#include "squarematrix.h"
using namespace std;

int main() {
	int fillingArray[28] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forSecondMatrix[28]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forDiagonalMatrix[4]{ 1, 2, 3, 4 };
	int forDiagonalMatrix2[7]{ 1, 2, 3, 4, 5, 6, 7};
	int forSquareMatrix[16]{ 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
	try
	{
		std::unique_ptr<BaseMatrix<int>> firstBaseMatr(new BaseMatrix<int>(4, 7, fillingArray, 28));
		std::unique_ptr<BaseMatrix<int>> secondBaseMatr(new BaseMatrix<int>(7, 4, forSecondMatrix, 28));
		cout << *(firstBaseMatr -> matrixToString()) << "\n";
		cout << *(secondBaseMatr -> matrixToString()) << "\n";
		
		std::unique_ptr <DiagonalMatrix<int>> firstDiagMatr(new DiagonalMatrix<int>(4, forDiagonalMatrix, 4));
		std::unique_ptr <DiagonalMatrix<int>> secondDiagMatr(new DiagonalMatrix<int>(4, forDiagonalMatrix2, 4));
		cout << *(firstDiagMatr -> matrixToString()) << "\n";
		cout << *(secondDiagMatr -> matrixToString()) << "\n";
		
		std::unique_ptr <SquareMatrix<int>> firstSquareMatr(new SquareMatrix<int>(4, forSquareMatrix, 16));
		std::unique_ptr <SquareMatrix<int>> secondSquareMatr(new SquareMatrix<int>(4, forSquareMatrix, 16));
		cout << *(firstSquareMatr->matrixToString()) << "\n";
		cout << *(secondSquareMatr->matrixToString()) << "\n";

		std::unique_ptr<BaseMatrix<int>> resultBaseMatr ((*firstDiagMatr) * (*secondSquareMatr));
		cout << *(resultBaseMatr -> matrixToString()) << "\n";
		
		//cout << (diagMatr * firstBaseMatr)->matrixToString() << "\n";
		//cout << result.matrixToString() << "\n";
		//cout << DiagonalMatrix<int>(7, 4).matrixToString();

	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << '\n';
	}
	return 0;
}