#include "pch.h"
#include "GraphicsWorld.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "CornerCut.h"
#include <iostream>

using namespace std;

void GraphicsWorld::run() {

	// =================================== PART 1 =======================================
	cout << "\nThis program has been written by: Aaron Leung";
	cout << "\nSubmitted at: April 12, 2019\n";
	cout << "\nTesting Functions in class Point:" << endl;
	Point m(6, 8);
	Point n(6, 8);
	n.setx(9);
	m.display();
	n.display();
	cout << "\nThe distance between two points m and n is: " << m.distance(n);

	cout << "\nTesting Functions in class Square:" << endl;
	Square s(5, 7, 12, "SQUARE - S");
	s.display();
	cout << "The area of " << s.getName() << " is: " << s.area() << "\n";
	cout << "The perimeter of " << s.getName() << " is: " << s.perimeter() << "\n";
	cout << "\nTesting Functions in class Rectangle:" << endl;
	Rectangle a(5, 7, 12, 15, "RECTANGLE A");
	a.display();
	Rectangle b(16, 7, 8, 9, "RECTANGLE B");
	b.display();
	cout << "The area of " << a.getName() << " is: " << a.area() << "\n";
	cout << "The perimeter of " << a.getName() << " is: " << a.perimeter() << "\n";
	double d = a.distance(b);
	cout << "\nThe distance between two rectangles is: " << d;
	cout << "\nTesting copy constructor in class Rectangle:" << endl;
	Rectangle rec1 = a;
	rec1.display();
	cout << "\nTesting assignment operator in class Rectangle:" << endl;
	Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
	rec2 = a;
	rec2.display();
	cout << "\nTesting Functions in class Circle:" << endl;
	Circle c(3, 5, 9, "CIRCLE C");
	c.display();
	cout << "The area of " << c.getName() << " is: " << c.area() << endl;
	cout << "The perimeter of " << c.getName() << " is: " << c.perimeter() << endl;
	d = a.distance(c);
	cout << "\nThe distance between rectangle a and circle c is: " << d << endl;

	// =================================== PART 2 =============================================
	CornerCut rc(6, 5, 10, 12, 9, "CornerCut rc");
	rc.display();
	cout << "The area of " << rc.getName() << " is: " << rc.area();
	cout << "\nThe perimeter of " << rc.getName() << " is: " << rc.perimeter();
	d = rc.distance(c);
	cout << "\nThe distance between rc and c is: " << d << endl;
	// Using array of Shape pointers:
	Shape* sh[4];
	sh[0] = &s;
	sh[1] = &a;
	sh[2] = &c;
	sh[3] = &rc;
	sh[0]->display();
	cout << "\nThe area of " << sh[0]->getName() << "is: " << sh[0]->area();
	cout << "\nThe perimeter of " << sh[0]->getName() << " is: " << sh[0]->perimeter() << endl;
	sh[1]->display();
	cout << "\nThe area of " << sh[1]->getName() << "is: " << sh[1]->area();
	cout << "\nThe perimeter of " << sh[0]->getName() << " is: " << sh[1]->perimeter() << endl;
	sh[2]->display();
	cout << "\nThe area of " << sh[2]->getName() << "is: " << sh[2]->area();
	cout << "\nThe circumference of " << sh[2]->getName() << " is: " << sh[2]->perimeter() << endl;
	sh[3]->display();
	cout << "\nThe area of " << sh[3]->getName() << "is: " << sh[3]->area();
	cout << "\nThe perimeter of " << sh[3]->getName() << " is: " << sh[3]->perimeter();
	cout << "\nTesting copy constructor in class CornerCut:" << endl;
	CornerCut cc = rc;
	cc.display();
	cout << "\nTesting assignment operator in class CornerCut:" << endl;
	CornerCut cc2(2, 5, 100, 12, 9, "CornerCut cc2");
	cc2.display();
	cc2 = cc;
	cc2.display();

}


