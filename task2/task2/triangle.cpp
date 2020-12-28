#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(){
	initializer(Point(), Point(), Point());
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c){
	initializer(a, b, c);
}
Triangle::Triangle(const Triangle& source){
	initializer(source.points.at(0), source.points.at(1), source.points.at(2));
}
double Triangle::squareOfTriangle() const {
	double p = (getLenAB() + getLenBC() + getLenCA()) / 2; //semi-perimeter

	return (std::sqrt(p*(p - getLenAB())*(p - getLenBC())*(p - getLenCA())));
}

double Triangle::getLenAB() const {
	return points.at(0).distanceTo(points.at(1));
}

double Triangle::getLenBC() const {
	return points.at(1).distanceTo(points.at(2));
}

double Triangle::getLenCA() const {
	return points.at(2).distanceTo(points.at(0));
}

void Triangle::initializer(const Point& a, const Point& b, const Point& c) {
	points.resize(3);
	points.at(0) = a;
	points.at(1) = b;
	points.at(2) = c;

}
