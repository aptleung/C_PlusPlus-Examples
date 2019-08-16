#include "pch.h"
#include "Point.h"
#include "math.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape(double x, double y, const char *name):origin(x,y){
	int length = strlen(name);
	shapeName = new char[length + 1];
	strcpy_s(shapeName, (length + 1), name);
}

Shape::Shape(Shape &sh):origin(sh.origin.getx(), sh.origin.gety()) {
	copy(sh);
}

Shape::~Shape() {
	destroy();
}

Shape & Shape::operator=(Shape &sh) {
	copy(sh);
	origin = Point(sh.origin.getx(), sh.origin.gety());
	return *this;
}

void Shape::destroy() {
	delete[] shapeName;
}

void Shape::copy(const Shape &sh) {
	int length = strlen(sh.shapeName);
	shapeName = new char[length + 1];
	strcpy_s(shapeName, (length + 1), sh.shapeName);
}

double Shape::distance(Shape &a, Shape &b) {
	return Point::distance(a.origin, b.origin);
}

double Shape::distance(Shape &other) {
	return origin.distance(other.origin);
}

void Shape::move(double dx, double dy) {
	origin.setx(origin.getx() + dx);
	origin.sety(origin.gety() + dy);
}

void Shape::display() {
	cout << "Shape Name: " << shapeName << endl;
	origin.display();
}

const Point& Shape::getOrigin() {
	return origin;
}

const char* Shape::getName() {
	return shapeName;
}