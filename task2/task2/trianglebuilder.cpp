#include "trianglebuilder.h"
#include <cmath>
#include <stdexcept>

TriangleBuilder* TriangleBuilder::builderPtr = nullptr;

TriangleBuilderDestroyer TriangleBuilder::destroyer;

TriangleBuilderDestroyer::~TriangleBuilderDestroyer() {
    delete (builderPtr->startOfRespChain-> nextPtr-> nextPtr);
    delete (builderPtr->startOfRespChain-> nextPtr);
    delete (builderPtr->startOfRespChain);
    delete builderPtr;
}

void TriangleBuilderDestroyer::initialize(TriangleBuilder* p) {
    builderPtr = p;
}

TriangleBuilder::TriangleBuilder() : startOfRespChain(nullptr) {}

TriangleBuilder::TriangleBuilder(const TriangleBuilder&) : startOfRespChain(nullptr) {}

TriangleBuilder::~TriangleBuilder() {}

TriangleBuilder& TriangleBuilder::getObject() {
    if (!builderPtr) {
        builderPtr = new TriangleBuilder();
        destroyer.initialize(builderPtr);
        EquilateTriangleBuilder* equilateTriangle = new EquilateTriangleBuilder();
        RightTriangleBuilder* rightTriangle = new RightTriangleBuilder();
        BaseTriangleBuilder* baseTriangle = new BaseTriangleBuilder();
        equilateTriangle->setNext(rightTriangle)->setNext(baseTriangle);
        builderPtr-> startOfRespChain = equilateTriangle;
    }
    return *builderPtr;
}

void TriangleBuilder::checkTriangle(const Point& a, const Point& b, const Point& c) const {
    if (((a.distanceTo(b) + b.distanceTo(c)) <= c.distanceTo(a))
        || ((b.distanceTo(c) + c.distanceTo(a)) <= a.distanceTo(b))
        || ((c.distanceTo(a) + a.distanceTo(b)) <= b.distanceTo(c))
        || (a == b) || (b == c) || (a == c))
    {
        throw std::invalid_argument("invalid points");
    }
}

Triangle* TriangleBuilder::createTriangle(const Point& a, const Point& b, const Point& c) {
    checkTriangle(a, b, c);
    return (startOfRespChain->createTriangle(a, b, c));
}
