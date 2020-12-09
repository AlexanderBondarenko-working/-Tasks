#include <iostream>
#include <exception>
#include "basematrix.h"
using namespace std;

int main() {
	int fillingArray[16] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3 };
	int forNullMatrix[16]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3 };
	try
	{
		BaseMatrix objOfBaseMatr(4, 4, fillingArray, 16);
		BaseMatrix NullMatr(4, 4, forNullMatrix, 16);

	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << '\n';
	}
	return 0;
}