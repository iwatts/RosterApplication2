// RosterApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "roster.h"

int main()
{
	string userInput = "";
	bool recognizedInput;
	int i = 0;
	int studentCount = 30;
	Roster* classRoster = new Roster(studentCount);
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Isaac,Watts,iwatts@wgu.edu,32,30,30,30,SOFTWARE"
	};
	int studentDataDefaultSize = *(&studentData + 1) - studentData;

	cout << "Loading Defaults... [" << studentDataDefaultSize << "]" << endl;
	for (i = 0; i < studentDataDefaultSize; i++) {
		classRoster->parseUserInputAndAdd(studentData[i]);
	}
	cout << "Loaded" << endl;


	cout << "Commands" << endl;
	cout << left << setw(18) << "q: Quit";
	cout << left << setw(20) << "p: Print All";
	cout << left << setw(20) << "a: Add Student";
	cout << left << setw(20) << "r: Remove Student";
	cout << endl;

	while (userInput != "q") {
		cin >> userInput;
		recognizedInput = false;
		for (i = 0; i < userInput.length(); i++) {
			if (isupper(userInput.at(i))) userInput.at(i) = tolower(userInput.at(i));
		}

		if (userInput == "p") {
			cout << left << setw(5) << "ID";
			cout << left << setw(15) << "First Name";
			cout << left << setw(15) << "Last Name";
			cout << left << setw(30) << "Email";
			cout << left << setw(5) << "Age";
			cout << left << setw(10) << "Course 1";
			cout << left << setw(10) << "Course 2";
			cout << left << setw(10) << "Course 3";
			cout << left << setw(10) << "Degree";
			cout << endl;
			classRoster->printAll();
			recognizedInput = true;
		}
		if (userInput == "r") {
			cout << "Enter ID to remove:" << endl;
			cin >> userInput;
			// classRoster->remove(userInput);
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
