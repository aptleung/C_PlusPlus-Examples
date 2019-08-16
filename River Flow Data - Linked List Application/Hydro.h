#pragma once

#include "Flowlist.h"
#include <iomanip>

void displayHeader();
int readData(Flowlist &data);
int menu();
void display(Flowlist &data);
void addData(Flowlist &data);
void removeData(Flowlist &data);
double average(Flowlist &data);
double median(Flowlist &data);
void saveData(Flowlist &data);
void pressEnter();

