#include "pch.h"
#include "CornerCut.h"
#include <iostream>

using namespace std;

CornerCut::CornerCut(double x, double y, double w, double l, double r, const char *name) :Circle(x, y, r, name), Rectangle(x, y, w, l, name), Shape(x, y, name) {

}

CornerCut::~CornerCut() {

}

double CornerCut::area() {
	double rectArea = Rectangle::area();
	double circArea = Circle::area();
	return rectArea - (0.25 * circArea);
}

double CornerCut::perimeter() {
	double rectPerim = Rectangle::perimeter();
	double circPerim = Circle::perimeter();

	return (rectPerim - (getRadius() * 2)) + (0.25 * circPerim);
}

void CornerCut::display() {
	cout << "CornerCut Name: " << shapeName << endl;
	origin.display();
	cout << "Width: " << getSideA() << endl;
	cout << "Length: " << getSideB() << endl;
	cout << "Radius Of Cut: " << getRadius() << endl;
}