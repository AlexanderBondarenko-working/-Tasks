# include "point.h"
#ifndef TASK2_TRIANGLE_H_ 
#define TASK2_TRIANGLE_H_ 

class Triangle {
	Point a;
	Point b;
	Point c;
	double lenOfVector(const Point& firstPoint, const Point& secondPoint) const;
	void checkTriangle() const;
public:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& source);
	virtual double squareOftriangle() const;
	double getLenAB() const;
	double getLenBC() const;
	double getLenCA() const;
};

#endif //TASK2_TRIANGLE_H_ 