#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(){}
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}
Triangle::Triangle(const Triangle& source) : a(a), b(b), c(c) {}

double Triangle::squareOftriangle() const {
	double p = (getLenAB() + getLenBC() + getLenCA()) / 2; //semi-perimeter

	return (std::sqrt(p*(p - getLenAB())*(p - getLenBC())*(p - getLenCA())));
}

double Triangle::getLenAB() const {
	return lenOfVector(a, b);
}

double Triangle::getLenBC() const {
	return lenOfVector(b, c);
}

double Triangle::getLenCA() const {
	return lenOfVector(c, a);
}

double Triangle::lenOfVector(const Point& firstPoint, const Point& secondPoint) const {
	return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}