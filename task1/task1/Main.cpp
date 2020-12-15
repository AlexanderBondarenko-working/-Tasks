#include <exception>
#include "basematrix.h"
#include "diagonalmatrix.h"
using namespace std;

int main() {
	int fillingArray[28] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forNullMatrix[28]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forDiagonalMatrix[4]{ 1, 2, 3, 4 };
	int forDiagonalMatrix2[7]{ 1, 2, 3, 4, 5, 6, 7};
	try
	{
		BaseMatrix<int> firstBaseMatr(4, 7, fillingArray, 28);
		cout << firstBaseMatr.matrixToString() << "\n";
		BaseMatrix<int> secondBaseMatr(7, 4, forNullMatrix, 28);
		cout << secondBaseMatr.matrixToString() << "\n";
		DiagonalMatrix<int> diagMatr(7, 4, forDiagonalMatrix, 4);
		DiagonalMatrix<int> diagMatr2(4, 7, forDiagonalMatrix2, 7);
		cout << diagMatr.matrixToString() << "\n";
		cout << diagMatr2.matrixToString() << "\n";
		cout << (diagMatr * diagMatr2) -> matrixToString() << "\n";
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