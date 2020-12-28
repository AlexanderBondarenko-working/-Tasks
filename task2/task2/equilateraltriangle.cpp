#include "equilateraltriangle.h"
#include <cmath>

EquilateralTriangle::EquilateralTriangle() : Triangle() {}
EquilateralTriangle::EquilateralTriangle(const Point& a, const Point& b, const Point& c) : Triangle(a, b, c) {}
EquilateralTriangle::EquilateralTriangle(const EquilateralTriangle& source) : Triangle(source) {}
double EquilateralTriangle::squareOfTriangle() const {
	return ((std::sqrt(3) * std::pow(getLenAB(), 2)) / 4.0);
}