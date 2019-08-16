#pragma once

class Point {

private:

	double x_coord;
	double y_coord;
	int id;
	static int count;
	static int id_count;

	void destroy();

public:

	Point(double x, double y);
	~Point();

	void display();
	double getx();
	double gety();
	int getID();
	void setx(double x);
	void sety(double y);

	int counter();
	double distance(Point &other_point);
	static double distance(Point &a, Point &b);

};
