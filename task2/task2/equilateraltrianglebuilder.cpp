#include "equilateraltrianglebuilder.h"
#include "equilateraltriangle.h"

EquilateTriangleBuilder::EquilateTriangleBuilder(){}

Triangle* EquilateTriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c) {
	if (((a.distanceTo(b) == b.distanceTo(c)) && (b.distanceTo(c) == c.distanceTo(a)))) {
		EquilateralTriangle* tempTriangle = new EquilateralTriangle(a, b, c);
		return tempTriangle;
	}
	return AbstractTriangleBuilder::createTriangle(a, b, c);
}