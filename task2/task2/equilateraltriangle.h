#ifndef TASK2_EQUILATERALTRIANGLE_H_ 
#define TASK2_EQUILATERALTRIANGLE_H_ 

#include "triangle.h"

class EquilateralTriangle : public Triangle {
protected:
	EquilateralTriangle();
	EquilateralTriangle(const Point& a, const Point& b, const Point& c);
	EquilateralTriangle(const EquilateralTriangle& source);
public:
	virtual double squareOfTriangle() const;
	friend class EquilateTriangleBuilder;
};

#endif //TASK2_EQUILATERALTRIANGLE_H_