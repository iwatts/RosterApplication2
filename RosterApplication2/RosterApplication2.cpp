// RosterApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "roster.h"

int main()
{
	string userInput = "";
	Roster classRoster;
	bool recognizedInput;
	int i = 0;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
	};


	cout << "Commands" << endl;
	cout << "q: Quit\tp: Print All\ta: Add Student\tr: Remove Student" << endl;

	while (userInput != "q") {
		cin >> userInput;
		recognizedInput = false;
		for (i = 0; i < userInput.length(); i++) {
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
			// generate id, get userinput for the rest
			// classRoster.addStudent();
			recognizedInput = true;
		}

		if (!recognizedInput && userInput != "q") {
			cout << "Input not recognized, please refer to the Commands for valid inputs" << endl;
		}
	}

}
