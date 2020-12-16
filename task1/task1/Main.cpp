#include <exception>
#include "basematrix.h"
#include "diagonalmatrix.h"
#include "squarematrix.h"
using namespace std;

int main() {
	double fillingArray[28] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	double forSecondMatrix[28]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	double forDiagonalMatrix[4]{ 1, 2, 3, 4 };
	double forDiagonalMatrix2[7]{ 1, 2, 3, 4, 5, 6, 7};
	double forSquareMatrix[16]{ 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
	try
	{
		std::unique_ptr<BaseMatrix<double>> firstBaseMatr(new BaseMatrix<double>(4, 7, fillingArray, 28));
		std::unique_ptr<BaseMatrix<double>> secondBaseMatr(new BaseMatrix<double>(7, 4, forSecondMatrix, 28));
		cout << firstBaseMatr -> matrixToString() << "\n";
		cout << secondBaseMatr -> matrixToString() << "\n";
		
		std::unique_ptr <DiagonalMatrix<double>> firstDiagMatr(new DiagonalMatrix<double>(7, 4, forDiagonalMatrix, 4));
		std::unique_ptr <DiagonalMatrix<double>> secondDiagMatr(new DiagonalMatrix<double>(4, 7, forDiagonalMatrix2, 4));
		cout << firstDiagMatr -> matrixToString() << "\n";
		cout << secondDiagMatr -> matrixToString() << "\n";
		
		std::unique_ptr <SquareMatrix<double>> firstSquareMatr(new SquareMatrix<double>(4, forSquareMatrix, 16));
		std::unique_ptr <SquareMatrix<double>> secondSquareMatr(new SquareMatrix<double>(4, forSquareMatrix, 16));
		cout << firstSquareMatr->matrixToString() << "\n";
		cout << secondSquareMatr->matrixToString() << "\n";

		std::unique_ptr<BaseMatrix<double>> resultBaseMatr ((*firstSquareMatr) * (*secondSquareMatr));
		cout << resultBaseMatr -> matrixToString() << "\n";
		
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