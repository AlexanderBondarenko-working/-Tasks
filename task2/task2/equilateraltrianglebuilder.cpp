#include "equilateraltrianglebuilder.h"
#include "equilateraltriangle.h"

Triangle* EquilateTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
	if (triangleCheckForBuilder(a, b, c)) {
		EquilateralTriangle* tempTriangle = new EquilateralTriangle(a, b, c);
		return tempTriangle;
	}
	return AbstractTriangleBuilder::getTriangle(a, b, c);
}

bool EquilateTriangleBuilder::triangleCheckForBuilder(const Point& a, const Point& b, const Point& c) {
	if ((lenOfVector(a, b) == lenOfVector(b, c)) && (lenOfVector(b, c) == lenOfVector(c, a))) {
		return true;
	}
	return false;
}