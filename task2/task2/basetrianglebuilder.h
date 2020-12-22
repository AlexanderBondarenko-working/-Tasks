#include "abstracttrianglebuilder.h"

#ifndef TASK2_BASETRIANGLEBUILDER_H_ 
#define TASK2_BASETRIANGLEBUILDER_H_ 

class BaseTriangleBuilder : public AbstractTriangleBuilder {
public:
	virtual Triangle* getTriangle(const Point& a, const Point& b, const Point& c);
	virtual bool triangleCheckForBuilder(const Point& a, const Point& b, const Point& c);
};

#endif //TASK2_ISOSCELESTTRIANGLEBUILDER_H_