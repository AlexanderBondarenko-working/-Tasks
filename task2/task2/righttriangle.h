#include "triangle.h"
#ifndef TASK2_RIGHTTRIANGLE_H_ 
#define TASK2_RIGHTTRIANGLE_H_ 

class RightTriangle : public Triangle {
protected:
	RightTriangle();
	RightTriangle(const Point& a, const Point& b, const Point& c);
	RightTriangle(const RightTriangle& source);
public:
	virtual double squareOftriangle() const;
	friend class RightTriangleBuilder;
};


#endif //TASK2_RIGHTTRIANGLE_H_ 