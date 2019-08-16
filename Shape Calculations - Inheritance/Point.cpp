#include "pch.h"
#include "Point.h"
#include "math.h"
#include <iostream>

using namespace std;

Point::Point(double x, double y) {
	x_coord = x;
	y_coord = y;
	id = 1000 + id_count;
	count++;
	id_count++;
}

Point::~Point() {
	destroy();
}

void Point::destroy() {
	count--;
}

void Point::display() {
	cout << "X-Coordinate: " << x_coord << endl;
	cout << "Y-Coordinate: " << y_coord << endl;
}

double Point::distance(Point &a, Point &b) {
	return sqrt(pow((a.x_coord - b.x_coord), 2) + pow((a.y_coord - b.y_coord), 2));
}

double Point::distance(Point &other_point) {
	return sqrt(pow((x_coord - other_point.x_coord), 2) + pow((y_coord - other_point.y_coord), 2));
}

int Point::counter() {
	return count;
}

double Point::getx() {
	return x_coord;
}

double Point::gety() {
	return y_coord;
}

int Point::getID() {
	return id;
}

void Point::setx(double x) {
	x_coord = x;
}

void Point::sety(double y) {
	y_coord = y;
}



