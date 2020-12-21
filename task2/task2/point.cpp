# include "point.h"
#include <stdexcept>

Point::Point() : x(0.0), y(0.0) {}
Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(const Point& source) {
	checkPoint(source, "invalid source");
	x = source.x;
	y = source.y;
}
Point& Point::operator = (const Point& source) {
	checkPoint(source, "invalid source");
	x = source.x;
	y = source.y;
	return *this;
}
bool Point::operator == (const Point& secondPoint) const {
	checkPoint(secondPoint, "Invalid second argument");
	return ((this->x == secondPoint.x) || (this->y == secondPoint.y));
}
Point Point::operator - (const Point& secondPoint) const {//??????? ?????? ??????????
	checkPoint(secondPoint, "Invalid second argument");
	return Point((this->x - secondPoint.x), (this->y - secondPoint.y));
}
double Point::getX() const {
	return this->x;
}
double Point::getY() const {
	return this->y;
}
Point::~Point() {}
void Point::checkPoint(const Point& source, const char* message) const {
	if (&source == NULL) {
		throw std::invalid_argument(message);
	}
}