#ifndef TASK2_BASETRIANGLEBUILDER_H_ 
#define TASK2_BASETRIANGLEBUILDER_H_

#include "abstracttrianglebuilder.h"

class BaseTriangleBuilder : public AbstractTriangleBuilder {
protected:
	BaseTriangleBuilder();
	virtual Triangle* createTriangle(const Point& a, const Point& b, const Point& c);
	friend class TriangleBuilder;
};

#endif //TASK2_ISOSCELESTTRIANGLEBUILDER_H_