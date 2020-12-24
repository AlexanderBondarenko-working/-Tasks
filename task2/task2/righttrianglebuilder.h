#ifndef TASK2_RIGHTTRIANGLEBUILDER_H_ 
#define TASK2_RIGHTTRIANGLEBUILDER_H_ 

#include "abstracttrianglebuilder.h"

class RightTriangleBuilder : public AbstractTriangleBuilder {
protected:
	RightTriangleBuilder();
	virtual Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
	virtual bool triangleCheckForBuilder(const Point& a, const Point& b, const Point& c);
	friend class TriangleBuilder;
};

#endif //TASK2_RIGHTTRIANGLEBUILDER_H_