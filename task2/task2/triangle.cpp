#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(){
	fillvector(Point(), Point(), Point());
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c){
	fillvector(a, b, c);
}
Triangle::Triangle(const Triangle& source){
	fillvector(source.points.at(0), source.points.at(1), source.points.at(2));
}
double Triangle::squareOftriangle() const {
	double p = (getLenAB() + getLenBC() + getLenCA()) / 2; //semi-perimeter

	return (std::sqrt(p*(p - getLenAB())*(p - getLenBC())*(p - getLenCA())));
}

double Triangle::getLenAB() const {
	return lenOfSide(points.at(0), points.at(1));
}

double Triangle::getLenBC() const {
	return lenOfSide(points.at(1), points.at(2));
}

double Triangle::getLenCA() const {
	return lenOfSide(points.at(2), points.at(0));
}

double Triangle::lenOfSide(const Point& firstPoint, const Point& secondPoint) const {
	return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}

void Triangle::fillvector(const Point& a, const Point& b, const Point& c) {
	points.resize(3);
	points.at(0) = a;
	points.at(1) = b;
	points.at(2) = c;

}
