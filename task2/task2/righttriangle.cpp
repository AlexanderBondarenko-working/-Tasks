#include "righttriangle.h"
#include <cmath>

RightTriangle::RightTriangle() : Triangle() {}
RightTriangle::RightTriangle(const Point& a, const Point& b, const Point& c) : Triangle(a, b, c) {}
RightTriangle::RightTriangle(const RightTriangle& source) : Triangle(source) {}
double RightTriangle::squareOftriangle() const {
	// 90 degree angle in b
	return (getLenAB() * getLenBC() / 2);
}