# include "point.h"
#ifndef TASK2_TRIANGLE_H_ 
#define TASK2_TRIANGLE_H_ 

class Triangle {
	Point a;
	Point b;
	Point c;
public:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& source);
	double squareOftriangle() const;
};

#endif //TASK2_TRIANGLE_H_ 