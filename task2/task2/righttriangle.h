#include "triangle.h"
#ifndef TASK2_RIGHTTRIANGLE_H_ 
#define TASK2_RIGHTTRIANGLE_H_ 

class RightTriangle : public Triangle {
	RightTriangle();
	RightTriangle(const Point& a, const Point& b, const Point& c);
	RightTriangle(const RightTriangle& source);
	virtual double squareOftriangle() const;
};


#endif //TASK2_RIGHTTRIANGLE_H_ 