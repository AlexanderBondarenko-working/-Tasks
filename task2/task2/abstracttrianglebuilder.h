#ifndef TASK2_ABSTRACTTRIANGLEBUILDER_H_ 
#define TASK2_ABSTRACTTRIANGLEBUILDER_H_ 

#include "triangle.h"

class AbstractTriangleBuilder {
	AbstractTriangleBuilder* nextPtr;
protected:
	AbstractTriangleBuilder();
	AbstractTriangleBuilder* setNext(AbstractTriangleBuilder* nextPtr);
	virtual Triangle* createTriangle(const Point& a, const Point& b, const Point& c);
	friend class TriangleBuilder;
	friend class TriangleBuilderDestroyer;
};
#endif //TASK2_ABSTRACTTRIANGLEBUILDER_H_ 