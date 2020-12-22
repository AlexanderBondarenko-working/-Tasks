#include "triangle.h"

#ifndef TASK2_ABSTRACTTRIANGLEBUILDER_H_ 
#define TASK2_ABSTRACTTRIANGLEBUILDER_H_ 

class AbstractTriangleBuilder {
	AbstractTriangleBuilder* nextPtr;
public:
	AbstractTriangleBuilder* setNext(AbstractTriangleBuilder* handler);
	virtual Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
	double lenOfVector(const Point& firstPoint, const Point& secondPoint);
	virtual bool triangleCheckForBuilder(const Point& a, const Point& b, const Point& c) = 0;
};
#endif //TASK2_ABSTRACTTRIANGLEBUILDER_H_ 