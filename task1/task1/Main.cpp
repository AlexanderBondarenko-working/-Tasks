#include <exception>
#include "basematrix.h"
#include "diagonalmatrix.h"
using namespace std;

int main() {
	int fillingArray[28] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forNullMatrix[28]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	int forDiagonalMatrix[4]{ 1, 2, 3, 4 };
	try
	{
		BaseMatrix firstBaseMatr(4, 7, fillingArray, 28);
		//objOfBaseMatr.out();
		BaseMatrix secondBaseMatr(7, 4, forNullMatrix, 28);
		DiagonalMatrix diagMatr(7, 4, forDiagonalMatrix, 4);
		firstBaseMatr.out();
		diagMatr.out();
		BaseMatrix result = (firstBaseMatr * diagMatr); //нельзя 
		result.out();

	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << '\n';
	}
	return 0;
}