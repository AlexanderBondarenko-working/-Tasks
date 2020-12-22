#include "abstracttrianglebuilder.h"

#ifndef TASK2_ISOSCELESTTRIANGLEBUILDER_H_ 
#define TASK2_ISOSCELESTTRIANGLEBUILDER_H_ 

class IsoscelestTriangleBuilder : public AbstractTriangleBuilder {
	virtual Triangle getTriangle(const Point& a, const Point& b, const Point& c);
};

#endif //TASK2_ISOSCELESTTRIANGLEBUILDER_H_