#include "triangle.h"
#include "equilateraltrianglebuilder.h"
#include "righttrianglebuilder.h"
#include "basetrianglebuilder.h"
#ifndef TASK2_TRIANGLEBUILDER_H_ 
#define TASK2_TRIANGLEBUILDER_H_ 

class TriangleBuilder
{
    TriangleBuilder() {}
    TriangleBuilder(const TriangleBuilder&);
    TriangleBuilder& operator=(TriangleBuilder&);
    void checkTriangle();
    EquilateTriangleBuilder * startOfRespChain;
    
public:
    Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
    static TriangleBuilder& getInstance();
    //void setChainOfResp();
};

#endif //TASK2_TRIANGLEBUILDER_H_
