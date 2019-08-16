#include "pch.h"
#include "Square.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Square::Square(double x, double y, double a, const char *name) :Shape(x, y, name) {
	side_a = a;
}

Square::~Square() {

}

double Square::area() {
	return side_a * side_a;
}

double Square::perimeter() {
	return side_a * 4;
}

void Square::display() {
	cout << "Square Name: " << shapeName << endl;
	origin.display();
}

double Square::getSideA() {
	return side_a;
}

void Square::setSideA(double a) {
	side_a = a;
}