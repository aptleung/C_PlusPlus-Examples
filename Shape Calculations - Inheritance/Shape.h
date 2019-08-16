#pragma once
#include "Point.h"


class Shape {

protected:

	Point origin;
	char *shapeName;
	void copy(const Shape &sh);
	void destroy();

public:

	Shape(double x, double y, const char  *name);
	Shape & operator=(Shape &sh);
	Shape(Shape &sh);
	~Shape();

	const Point& getOrigin();
	const char* getName();
	virtual void display();
	double distance(Shape &other);
	static double distance(Shape &a, Shape &b);
	void move(double dx, double dy);
	virtual double area() = 0;
	virtual double perimeter() = 0;

	

};