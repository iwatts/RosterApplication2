// RosterApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "roster.h"

int main()
{
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
	};
	string userInput = "";
	bool recognizedInput;

	roster newRoster;

	cout << "Commands" << endl;
	cout << "q: Quit\tp: Print All\ta: Add Student\tr: Remove Student" << endl;

	while (userInput != "q") {
		cin >> userInput;
		recognizedInput = false;
		for (int i = 0; i < userInput.length(); i++) {
			if (isupper(userInput.at(i))) userInput.at(i) = tolower(userInput.at(i));
		}

		if (userInput == "p") {
			newRoster.printAll();
			recognizedInput = true;
		}
		if (userInput == "r") {
			cout << "Enter ID to remove:" << endl;
			cin >> userInput;
			newRoster.remove(userInput);
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
