#include "abstracttrianglebuilder.h"
#include <cmath>

AbstractTriangleBuilder::AbstractTriangleBuilder() : nextPtr(nullptr) {}

AbstractTriangleBuilder* AbstractTriangleBuilder::setNext(AbstractTriangleBuilder* nextPtr) {
	this->nextPtr = nextPtr;
	return nextPtr;
}

Triangle* AbstractTriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c){
	if (this-> nextPtr) {
		return this-> nextPtr->createTriangle(a, b, c);
	}

	return nullptr;
}