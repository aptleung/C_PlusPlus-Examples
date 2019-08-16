#include "pch.h"
#include "Hydro.h"
#include "Flowlist.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	Flowlist data;
	int recordCount = readData(data);
	displayHeader();
	int quit = 0;

	while (true) {
		switch (menu()) {
		case 1:
			cout << "\n";
			display(data);
			cout << "Average Flow: " << average(data) << "\n";
			cout << "Median Flow: " << median(data) << "\n";
			break;

		case 2:
			addData(data);
			break;

		case 3:
			saveData(data);
			break;

		case 4:
			removeData(data);
			break;

		case 5:
			cout << "Program Terminated!\n";
			quit = 1;
			break;

		default:
			cout << "Invalid Input, Please Enter One of the Choices Above\n";
			break;
		}

		if (quit == 1) {
			break;
		}
		pressEnter();
	}

	Flowlist copy1;
	copy1 = data;
	// In the following section call addData to add
	// following records (year, flow) to copy1:
	// 2012 459.99
	// 2013 2000.34

	addData(copy1);
	addData(copy1);

	// Use the following code to create a copy of copy1 called copy2
	Flowlist copy2 = copy1;
	// removing three records from copy2

	copy2.remove(1922);
	copy2.remove(2003);
	copy2.remove(2001);

	// Display the values in three list copy 2, copy1, and x
	cout << "\n values in copy2 are:\n";
	display(copy2);
	cout << "\n values in copy1 are:\n";
	display(copy1);
	cout << "\n values in x are:\n";
	display(data);

	return 0;

}

void saveData(Flowlist &data) {
	const char *filename = "flow.txt";
	ofstream outfile;
	outfile.open(filename);

	if (!outfile) {
		cout << "Error Opening File. Program Terminating.\n";
		exit(1);
	}
	data.reset();
	const Node *cursor = data.cursor();
	while (cursor != NULL) {
		int year;
		double flow;
		year = cursor->item.year;
		flow = cursor->item.flow;
		outfile << year << setw(15) << flow << endl;
		cursor = cursor->next;
	}
	outfile.close();
	cout << "Data Saved to " << filename << "\n";
}

void removeData(Flowlist &data) {
	cout << "Please Enter the Year of Data to remove:\n";
	int year;
	cin >> year;
	while (cin.fail()) {
		cout << "Invalid Input. Try Again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> year;
	}
	data.remove(year);
}

void addData(Flowlist &data) {
	int year;
	double flow;
	cout << "Please Enter the Year for the Data:\n";
	cin >> year;
	while (cin.fail()) {
		cout << "Invalid Input. Try Again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> year;
	}

	cout << "Please Enter the Flow for this Year:\n";
	cin >> flow;
	while (cin.fail()) {
		cout << "Invalid Input. Try Again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> year;
	}

	ListItem temp = ListItem();
	temp.year = year;
	temp.flow = flow;
	data.insert(temp);

}

void display(Flowlist &data) {
	data.reset();
	cout << "Year\t\tFlow\n";
	while (data.isOn()) {
		ListItem temp = data.getItem(); 
		cout << temp.year << "\t\t" << temp.flow << '\n';
		data.forward();
	}
}

double median(Flowlist &data) {
	int counter = 1;
	data.reset();

	if (data.count() % 2 == 0) {
		while (counter < data.count() / 2) {
			data.forward();
			counter++;
		}
	}
	else {
		while (counter <= data.count() / 2) {
			data.forward();
			counter++;
		}
	}
	return data.getItem().flow;
}

double average(Flowlist &data) {
	data.reset();
	const Node *temp = data.cursor();
	double total = 0.0;
	while (temp != NULL) {
		total += temp->item.flow;
		temp = temp->next;
	}
	return total / data.count();
}

int readData(Flowlist &data) {
	int counter = 0;
	const char *file = "flow.txt";
	ifstream inputFile;
	inputFile.open(file);

	if (!inputFile) {
		cout << "Cannot Open the File, Program Terminating.\n";
		exit(1);
	}

	while (inputFile) {
		int year;
		double flow;
		inputFile >> year >> flow;
		ListItem temp = ListItem();
		temp.year = year;
		temp.flow = flow;
		data.insert(temp);
		counter++;
	}
	inputFile.close();
	return counter;
}

void displayHeader() {
	cout << "\nHEF Hydropower Studies - Winter 2019\n";
	cout << "Program: Flow Studies\n";
	cout << "Version: 1.0\n";
	cout << "Lab Section: B01\n";
	cout << "Instructor: M. Moshirpour\n";
	cout << "Teaching Assistant (s): Bob Doom\n";
	cout << "Produced By: Aaron Leung\n";
	pressEnter();
}

void pressEnter() {
	char input = 'x';
	cout << "<<< Press Enter to Continue >>>";
	cin.clear();
	cin.ignore();
	cin.get(input);
	while (input != '\n') {
		cin.get(input);
	}
}

int menu() {
	cout << "\nPlease Select One of the Following Operations:\n";
	cout << "1. Display Flow list, Average, and Median\n";
	cout << "2. Add Data\n";
	cout << "3. Save Data Into File\n";
	cout << "4. Remove Data\n";
	cout << "5. Quit\n";
	cout << "Enter Your Choice (1, 2, 3, 4, or 5)\n";

	int choice;
	cin >> choice;
	
	while (cin.fail()) {
		cout << "Invalid Input. Try Again.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}
	return choice;
}


