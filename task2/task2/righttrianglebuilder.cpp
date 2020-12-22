#include "righttrianglebuilder.h"
#include "righttriangle.h"

Triangle* RightTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
	if (triangleCheckForBuilder(a, b, c)) {
		RightTriangle* tempTriangle = new RightTriangle(a, b, c);
		return tempTriangle;
	}
	return AbstractTriangleBuilder::getTriangle(a, b, c);
}

bool RightTriangleBuilder::triangleCheckForBuilder(const Point& a, const Point& b, const Point& c) {
	if (!((a.getX() - b.getX()) * (b.getX() - c.getX()) + (a.getY() - b.getY()) * (b.getY() - c.getY()))
		|| !((b.getX() - c.getX()) * (c.getX() - a.getX()) + (b.getY() - c.getY()) * (c.getY() - a.getY()))
		|| !((c.getX() - a.getX()) * (a.getX() - b.getX()) + (c.getY() - a.getY()) * (a.getY() - b.getY())))
	{
		return true;
	}
	return false;
}