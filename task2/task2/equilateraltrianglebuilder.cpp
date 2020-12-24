#include "equilateraltrianglebuilder.h"
#include "equilateraltriangle.h"

EquilateTriangleBuilder::EquilateTriangleBuilder(){}

Triangle* EquilateTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
	if (triangleCheckForBuilder(a, b, c)) {
		EquilateralTriangle* tempTriangle = new EquilateralTriangle(a, b, c);
		return tempTriangle;
	}
	return AbstractTriangleBuilder::getTriangle(a, b, c);
}

bool EquilateTriangleBuilder::triangleCheckForBuilder(const Point& a, const Point& b, const Point& c) {
	if ((lenOfSide(a, b) == lenOfSide(b, c)) && (lenOfSide(b, c) == lenOfSide(c, a))) {
		return true;
	}
	return false;
}