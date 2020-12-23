#include "basetrianglebuilder.h"

BaseTriangleBuilder::BaseTriangleBuilder(){}

Triangle* BaseTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
	Triangle* tempTriangle = new Triangle(a, b, c);
	return tempTriangle;
}

bool BaseTriangleBuilder::triangleCheckForBuilder(const Point& a, const Point& b, const Point& c) {
	return true;
}