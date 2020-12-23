#include "righttriangle.h"
#include <cmath>

RightTriangle::RightTriangle() : Triangle() {}
RightTriangle::RightTriangle(const Point& a, const Point& b, const Point& c) : Triangle(a, b, c) {}
RightTriangle::RightTriangle(const RightTriangle& source) : Triangle(source) {}
double RightTriangle::squareOftriangle() const {
	if ((this-> getLenAB() > this-> getLenBC()) && (this-> getLenAB() > this-> getLenCA())) {
		return (this-> getLenBC() * this-> getLenCA() / 2.0);
	}
	if ((this-> getLenBC() > this-> getLenAB()) && (this-> getLenBC() > this-> getLenCA())) {
		return (this-> getLenAB() * this-> getLenCA() / 2.0);
	}

	return (this-> getLenAB() * this-> getLenBC() / 2.0);
}