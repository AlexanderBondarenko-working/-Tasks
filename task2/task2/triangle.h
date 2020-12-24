#ifndef TASK2_TRIANGLE_H_ 
#define TASK2_TRIANGLE_H_

#include "point.h"
#include <vector>

class Triangle {
	std::vector<Point> points;
	void fillvector(const Point& a, const Point& b, const Point& c);
protected:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& source);
	double getLenAB() const;
	double getLenBC() const;
	double getLenCA() const;
public:
	virtual double squareOfTriangle() const;
	friend class BaseTriangleBuilder;
};

#endif //TASK2_TRIANGLE_H_ 