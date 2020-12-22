#include "equilateraltriangle.h"
#include <cmath>

EquilateralTriangle::EquilateralTriangle() : Triangle() {}
EquilateralTriangle::EquilateralTriangle(const Point& a, const Point& b, const Point& c) : Triangle(a, b, c) {}
EquilateralTriangle::EquilateralTriangle(const EquilateralTriangle& source) : Triangle(source) {}
double EquilateralTriangle::squareOftriangle() const {
	//ab == bc
	return (getLenCA() * std::sqrt(std::pow(getLenAB(), 2) - std::pow(getLenCA(), 2) / 4) / 2);
}