// ENSF_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Point.h"
#include "math.h"
#include <iostream>
#include "GraphicsWorld.h"

using namespace std;

int Point::count = 0;
int Point::id_count = 0;

int main()
{
	GraphicsWorld gw;
	gw.run();

}

