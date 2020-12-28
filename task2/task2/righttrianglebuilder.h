#ifndef TASK2_RIGHTTRIANGLEBUILDER_H_ 
#define TASK2_RIGHTTRIANGLEBUILDER_H_ 

#include "abstracttrianglebuilder.h"

class RightTriangleBuilder : public AbstractTriangleBuilder {
protected:
	RightTriangleBuilder();
	virtual Triangle* createTriangle(const Point& a, const Point& b, const Point& c);
	friend class TriangleBuilder;
};

#endif //TASK2_RIGHTTRIANGLEBUILDER_H_