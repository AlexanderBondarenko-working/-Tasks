#include "abstracttrianglebuilder.h"
#include <cmath>

AbstractTriangleBuilder* AbstractTriangleBuilder::setNext(AbstractTriangleBuilder* handler) {
	this->nextPtr = handler;
	return handler;
}

double AbstractTriangleBuilder::lenOfVector(const Point& firstPoint, const Point& secondPoint) {
	return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}
//
//bool AbstractTriangleBuilder::checKTriangle(const Point& a, const Point& b, const Point& c) {
//	return ((((lenOfVector(a, b) + lenOfVector(b, c)) > lenOfVector(c, a))
//		|| ((lenOfVector(b, c) + lenOfVector(c, a)) > lenOfVector(a, b))
//		|| ((lenOfVector(c, a) + lenOfVector(a, b)) > lenOfVector(b, c))));
//
//}
//
Triangle* AbstractTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c){
	if (this-> nextPtr) {
		return this-> nextPtr->getTriangle(a, b, c);
	}

	return {};
}