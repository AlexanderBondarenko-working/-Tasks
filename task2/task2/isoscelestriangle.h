#include "triangle.h"

#ifndef TASK2_ISOSCELSTRIANGLE_H_ 
#define TASK2_ISOSCELSTRIANGLE_H_ 

class IsoscelesTriangle : public Triangle {
	IsoscelesTriangle();
	IsoscelesTriangle(const Point& a, const Point& b, const Point& c);
	IsoscelesTriangle(const IsoscelesTriangle& source);
	virtual double squareOftriangle() const;
};

#endif //TASK2_ISOSCELSTRIANGLE_H_