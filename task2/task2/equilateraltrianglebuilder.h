#ifndef TASK2_EQUILATERALTRIANGLEBUILDER_H_ 
#define TASK2_EQUILATERALTRIANGLEBUILDER_H_ 

#include "abstracttrianglebuilder.h"

class EquilateTriangleBuilder : public AbstractTriangleBuilder {
protected:
	EquilateTriangleBuilder();
	virtual Triangle* createTriangle(const Point& a, const Point& b, const Point& c);
	friend class TriangleBuilder;
};

#endif //TASK2_EQUILATERALTRIANGLEBUILDER_H_ 