#ifndef TASK2_TRIANGLEBUILDER_H_ 
#define TASK2_TRIANGLEBUILDER_H_ 

#include "triangle.h"
#include "equilateraltrianglebuilder.h"
#include "righttrianglebuilder.h"
#include "basetrianglebuilder.h"

class TriangleBuilder; 

class TriangleBuilderDestroyer
{
private:
    TriangleBuilder* builderPtr;

public:
    ~TriangleBuilderDestroyer();
    void initialize(TriangleBuilder* p);
};

class TriangleBuilder
{
private:
    static TriangleBuilder* builderPtr;
    static TriangleBuilderDestroyer destroyer;
protected:
    TriangleBuilder() { }
    TriangleBuilder(const TriangleBuilder&);
    TriangleBuilder& operator=(TriangleBuilder&);
    ~TriangleBuilder() { }
    friend class TriangleBuilderDestroyer;

    void checkTriangle(const Point& a, const Point& b, const Point& c) const;
    EquilateTriangleBuilder* startOfRespChain;
    double lenOfVector(const Point& firstPoint, const Point& secondPoint) const;
public:
    static TriangleBuilder& getObject();
    Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
};

#endif //TASK2_TRIANGLEBUILDER_H_