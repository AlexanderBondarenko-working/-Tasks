#include "equilateraltrianglebuilder.h"
#include "equilateraltriangle.h"
#include <cmath>

EquilateTriangleBuilder::EquilateTriangleBuilder(){}

Triangle* EquilateTriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c) {
	if((std::abs(a.distanceTo(b) - b.distanceTo(c)) < std::numeric_limits<double>::epsilon()) 
		&& (std::abs(b.distanceTo(c) - c.distanceTo(a)) < std::numeric_limits<double>::epsilon())){
		EquilateralTriangle* tempTriangle = new EquilateralTriangle(a, b, c);
		return tempTriangle;
	}
	return AbstractTriangleBuilder::createTriangle(a, b, c);
}