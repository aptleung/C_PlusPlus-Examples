#include "pch.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double x, double y, double a, double b, const char *name) :Square(x, y, a, name), Shape(x, y, name) {
	side_b = b;
}

Rectangle::~Rectangle() {

}

double Rectangle::area() {
	return side_b * getSideA();
}

double Rectangle::perimeter() {
	return side_b + side_b + getSideA() + getSideA();
}

void Rectangle::display() {
	cout << "Rectangle Name: " << shapeName << endl;
	origin.display();
}

double Rectangle::getSideB() {
	return side_b;
}

void Rectangle::setSideB(double b) {
	side_b = b;
}