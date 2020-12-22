#include "abstracttrianglebuilder.h"

#ifndef TASK2_RIGHTTRIANGLEBUILDER_H_ 
#define TASK2_RIGHTTRIANGLEBUILDER_H_ 

class RightTriangleBuilder : public AbstractTriangleBuilder {
	virtual Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
	virtual bool triangleCheckForBuilder(const Point& a, const Point& b, const Point& c);
};

#endif //TASK2_RIGHTTRIANGLEBUILDER_H_