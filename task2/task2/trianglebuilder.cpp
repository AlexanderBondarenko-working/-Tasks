#include "trianglebuilder.h"

TriangleBuilder& TriangleBuilder::getInstance() {
    static TriangleBuilder  builder;
    EquilateTriangleBuilder * equilateTriangle = new EquilateTriangleBuilder();
    RightTriangleBuilder * rightTriangle = new RightTriangleBuilder();
    BaseTriangleBuilder * baseTriangle = new BaseTriangleBuilder();
    equilateTriangle->setNext(rightTriangle)->setNext(baseTriangle);
    builder.startOfRespChain = equilateTriangle;

    return builder;
}

Triangle* TriangleBuilder::getTriangle(const Point& a, const Point& b, const Point& c) {
    return (startOfRespChain->getTriangle(a, b, c));
}