#include "triangle.h"
#include "equilateraltrianglebuilder.h"
#include "righttrianglebuilder.h"
#include "basetrianglebuilder.h"
#ifndef TASK2_TRIANGLEBUILDER_H_ 
#define TASK2_TRIANGLEBUILDER_H_ 

class TriangleBuilder
{
    TriangleBuilder();
    TriangleBuilder(const TriangleBuilder&);
    TriangleBuilder& operator=(TriangleBuilder&);
    void checkTriangle(const Point& a, const Point& b, const Point& c) const;
    EquilateTriangleBuilder * startOfRespChain;
    double lenOfVector(const Point& firstPoint, const Point& secondPoint) const;
    
public:
    Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
    static TriangleBuilder& getObject();
    //void setChainOfResp();
};

#endif //TASK2_TRIANGLEBUILDER_H_
