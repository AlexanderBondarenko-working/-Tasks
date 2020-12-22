#include "abstracttrianglebuilder.h"

#ifndef TASK2_EQUILATERALTRIANGLEBUILDER_H_ 
#define TASK2_EQUILATERALTRIANGLEBUILDER_H_ 

class EquilateTriangleBuilder : public AbstractTriangleBuilder {
public:
	virtual Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
	virtual bool triangleCheckForBuilder(const Point& a, const Point& b, const Point& c);
};

#endif //TASK2_EQUILATERALTRIANGLEBUILDER_H_ 