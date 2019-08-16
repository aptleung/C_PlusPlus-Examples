#pragma once

#include "Square.h"

class Rectangle : public Square {

private:

	double side_b;

public:

	Rectangle(double x, double y, double a, double b, const char *name);
	~Rectangle();

	double area();
	double perimeter();
	void display();

	double getSideB();
	void setSideB(double b);

};