#include "basetrianglebuilder.h"

BaseTriangleBuilder::BaseTriangleBuilder(){}

Triangle* BaseTriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c) {
	Triangle* tempTriangle = new Triangle(a, b, c);
	return tempTriangle;
}
