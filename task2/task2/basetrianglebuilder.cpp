#include "basetrianglebuilder.h"

Triangle* BaseTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
	Triangle* tempTriangle = new Triangle(a, b, c);
	return tempTriangle;
}