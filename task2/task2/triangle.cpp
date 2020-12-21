#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(){}
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}
Triangle::Triangle(const Triangle& source) : a(a), b(b), c(c) {}

double Triangle::squareOftriangle() const {
	double lenAB = std::sqrt(std::pow((a.getX() - b.getX()), 2) + std::pow((a.getY() - b.getY()),2));
	double lenBC = std::sqrt(std::pow((b.getX() - c.getX()), 2) + std::pow((b.getY() - c.getY()), 2));
	double lenCA = std::sqrt(std::pow((c.getX() - a.getX()), 2) + std::pow((c.getY() - a.getY()), 2));
	double p = (lenAB + lenBC + lenCA) / 2; //semi-perimeter

	return (std::sqrt(p*(p - lenAB)*(p - lenBC)*(p - lenCA)));
}