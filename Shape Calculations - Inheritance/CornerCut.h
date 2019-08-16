#pragma once

#include "Circle.h"
#include "Rectangle.h"

class CornerCut : public Circle, public Rectangle {

public:
	
	CornerCut(double x, double y, double w, double l, double r, const char* name);
	~CornerCut();

	void display();
	double area();
	double perimeter();

};