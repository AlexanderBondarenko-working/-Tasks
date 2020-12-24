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
    if (((lenOfVector(a, b) + lenOfVector(b, c)) <= lenOfVector(c, a))
        || ((lenOfVector(b, c) + lenOfVector(c, a)) <= lenOfVector(a, b))
        || ((lenOfVector(c, a) + lenOfVector(a, b)) <= lenOfVector(b, c))
        || (a == b) || (b == c) || (a == c))
    {
        throw std::invalid_argument("invalid points");
    }
}

Triangle* TriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
    checkTriangle(a, b, c);
    return (startOfRespChain->getTriangle(a, b, c));
}

double TriangleBuilder::lenOfVector(const Point& firstPoint, const Point& secondPoint) const {
    return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}