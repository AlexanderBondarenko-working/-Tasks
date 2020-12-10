#include <exception>
#include "basematrix.h"
using namespace std;

int main() {
	int fillingArray[28] { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6};
	int forNullMatrix[28]{ 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 6, 6 };
	try
	{
		BaseMatrix objOfBaseMatr(4, 7, fillingArray, 28);
		objOfBaseMatr.out();
		BaseMatrix nullMatr(7, 4, forNullMatrix, 28);
		nullMatr.out();
		BaseMatrix result = (objOfBaseMatr * nullMatr);
		result.out();

	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << '\n';
	}
	return 0;
}