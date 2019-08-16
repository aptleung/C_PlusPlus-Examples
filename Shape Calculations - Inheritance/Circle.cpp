#include "pch.h"
#include "Circle.h"
#include <iostream>
#include "math.h"

using namespace std;

Circle::Circle(double x, double y, double r, const char *name) :Shape(x, y, name) {
	radius = r;
}

Circle::~Circle() {

}

double Circle::area() {
	return 3.1415*pow(radius, 2);
}

double Circle::perimeter() {
	return 2 * 3.1415 * radius;
}

void Circle::display() {
	cout << "Circle Name: " << shapeName << endl;
	origin.display();
}

double Circle::getRadius() {
	return radius;
}

void Circle::setRadius(double r) {
	radius = r;
}