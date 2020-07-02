// RosterApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "roster.h"

int main()
{
	string userInput = "";
	bool recognizedInput;
	roster classRoster;


	cout << "Commands" << endl;
	cout << "q: Quit\tp: Print All\ta: Add Student\tr: Remove Student" << endl;

	while (userInput != "q") {
		cin >> userInput;
		recognizedInput = false;
		for (int i = 0; i < userInput.length(); i++) {
			if (isupper(userInput.at(i))) userInput.at(i) = tolower(userInput.at(i));
		}

		if (userInput == "p") {
			classRoster.printAll();
			recognizedInput = true;
		}
		if (userInput == "r") {
			cout << "Enter ID to remove:" << endl;
			cin >> userInput;
			classRoster.remove(userInput);
			recognizedInput = true;
		}
		if (userInput == "a") {
			cout << "Student Creation Wizard Goes Here" << endl;
			recognizedInput = true;
		}

		if (!recognizedInput && userInput != "q") {
			cout << "Input not recognized, please refer to the Commands for valid inputs" << endl;
		}
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control  
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
