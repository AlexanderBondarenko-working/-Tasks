#include "abstracttrianglebuilder.h"
#include <cmath>

AbstractTriangleBuilder::AbstractTriangleBuilder() : nextPtr(nullptr) {}

AbstractTriangleBuilder* AbstractTriangleBuilder::setNext(AbstractTriangleBuilder* nextPtr) {
	this->nextPtr = nextPtr;
	return nextPtr;
}

double AbstractTriangleBuilder::lenOfSide(const Point& firstPoint, const Point& secondPoint) {
	return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}

Triangle* AbstractTriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c){
	if (this-> nextPtr) {
		return this-> nextPtr->getTriangle(a, b, c);
	}

	return nullptr;
}