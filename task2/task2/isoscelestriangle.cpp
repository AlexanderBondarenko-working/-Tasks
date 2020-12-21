#include "isoscelestriangle.h"
#include <cmath>

IsoscelesTriangle::IsoscelesTriangle() : Triangle() {}
IsoscelesTriangle::IsoscelesTriangle(const Point& a, const Point& b, const Point& c) : Triangle(a, b, c) {}
IsoscelesTriangle::IsoscelesTriangle(const IsoscelesTriangle& source) : Triangle(source) {}
double IsoscelesTriangle::squareOftriangle() const {
	// 90 degree angle in b
	//ab == bc
	return (getLenCA() * std::sqrt(std::pow(getLenAB(), 2) - std::pow(getLenCA(), 2) / 4) / 2);
}