#include "abstracttrianglebuilder.h"
#include <cmath>
#include <stdexcept>

AbstractTriangleBuilder::AbstractTriangleBuilder() : nextPtr(nullptr) {}

AbstractTriangleBuilder* AbstractTriangleBuilder::setNext(AbstractTriangleBuilder* nextPtr) {
	this->nextPtr = nextPtr;
	return nextPtr;
}

Triangle* AbstractTriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c){
	if ((this-> nextPtr) == nullptr) {
		throw std::logic_error("nullptr pointer in chain");
	}
	return this->nextPtr->createTriangle(a, b, c);
}