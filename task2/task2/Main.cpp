#include <iostream>
#include "trianglebuilder.h"
#include "triangle.h"

using namespace std;

int main() {
	try {
		cout << ((TriangleBuilder::getObject()).createTriangle(Point(0, 6), Point(0, 4), Point(5, 8))->squareOfTriangle());
	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << '\n';
	}
	return 0;
}