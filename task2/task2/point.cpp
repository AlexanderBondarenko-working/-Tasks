# include "point.h"
#include <stdexcept>
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}
Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(const Point& source) {
	if (&source == NULL) {
		throw std::invalid_argument("invalid source");
	}
	x = source.x;
	y = source.y;
}
Point& Point::operator = (const Point& source) {
	if (&source == NULL) {
		throw std::invalid_argument("invalid source");
	}
	x = source.x;
	y = source.y;
	return *this;
}
bool Point::operator == (const Point& secondPoint) const {
	if (&secondPoint == NULL) {
		return false;
	}
	return ((this->x == secondPoint.x) && (this->y == secondPoint.y));
}

double Point::getX() const {
	return this->x;
}
double Point::getY() const {
	return this->y;
}
Point::~Point() {}

double Point::distanceTo(const Point& secondPoint) const {
	return std::sqrt(std::pow((this-> getX() - secondPoint.getX()), 2) + std::pow((this-> getY() - secondPoint.getY()), 2));
}

