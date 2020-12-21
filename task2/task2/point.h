#ifndef TASK2_POINT_H_ 
#define TASK2_POINT_H_ 

class Point {
	double x;
	double y;
	void checkPoint(const Point& source, const char* message) const;
public:
	Point();
	Point(double x, double y);
	Point(const Point& source);
	Point& operator = (const Point& source);
	bool operator == (const Point& secondPoint) const;
	Point operator - (const Point& secondPoint) const;
	double getX() const;
	double getY() const;
	~Point();
};


#endif //TASK2_POINT_H