#include "triangle.h"

#ifndef TASK2_EQUILATERALTRIANGLE_H_ 
#define TASK2_EQUILATERALTRIANGLE_H_ 

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle();
	EquilateralTriangle(const Point& a, const Point& b, const Point& c);
	EquilateralTriangle(const EquilateralTriangle& source);
	virtual double squareOftriangle() const;
};

#endif //TASK2_EQUILATERALTRIANGLE_H_