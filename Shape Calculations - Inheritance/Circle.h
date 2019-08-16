#pragma once

#include "Shape.h"

class Circle : virtual public Shape {

private:

	double radius;

public:

	Circle(double x, double y, double r, const char *name);
	~Circle();

	double perimeter();
	double area();
	void display();
	double getRadius();
	void setRadius(double r);
};