#include "trianglebuilder.h"
#include <cmath>
#include <stdexcept>

TriangleBuilder::TriangleBuilder() : startOfRespChain(nullptr) {}

TriangleBuilder& TriangleBuilder::getObject() {
    static TriangleBuilder  builder;
    EquilateTriangleBuilder * equilateTriangle = new EquilateTriangleBuilder();
    RightTriangleBuilder * rightTriangle = new RightTriangleBuilder();
    BaseTriangleBuilder * baseTriangle = new BaseTriangleBuilder();
    equilateTriangle->setNext(rightTriangle)->setNext(baseTriangle);
    builder.startOfRespChain = equilateTriangle;

    return builder;
}

Triangle* TriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
    checkTriangle(a, b, c);
    return (startOfRespChain->getTriangle(a, b, c));
}

double TriangleBuilder::lenOfVector(const Point& firstPoint, const Point& secondPoint) const {
    return std::sqrt(std::pow((firstPoint.getX() - secondPoint.getX()), 2) + std::pow((firstPoint.getY() - secondPoint.getY()), 2));
}

void TriangleBuilder::checkTriangle(const Point& a, const Point& b, const Point& c) const {
    if ( ((lenOfVector(a, b) + lenOfVector(b, c)) <= lenOfVector(c, a))
        || ((lenOfVector(b, c) + lenOfVector(c, a)) <= lenOfVector(a, b))
        || ((lenOfVector(c, a) + lenOfVector(a, b)) <= lenOfVector(b, c)) 
        || (a == b) || (b == c) || (a == c) )
    {
        throw std::invalid_argument("invalid points");
    }
}