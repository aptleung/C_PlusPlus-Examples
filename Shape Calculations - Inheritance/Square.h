#pragma once

#include "Shape.h"

class Square : virtual public Shape {

private:

	double side_a;

public:

	Square(double x, double y, double a, const char *name);
	~Square();

	double area();
	double perimeter();
	void display();
	double getSideA();
	void setSideA(double a);

};

