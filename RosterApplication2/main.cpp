// RosterApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "roster.h"

int main()
{

	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Written in C++" << endl;
	cout << "Isaac Watts - 000993384" << endl;

	string userInput = "";
	DegreeProgram degree = UNDECLARED;
	bool recognizedInput;
	int i = 0;
	int studentCount = 30;
	Roster* classRoster = new Roster(studentCount);
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Isaac,Watts,iwatts@wgu.edu,32,30,40,50,SOFTWARE"
	};
	int studentDataDefaultSize = *(&studentData + 1) - studentData;

	for (i = 0; i < studentDataDefaultSize; i++) {
		classRoster->parseUserInputAndAdd(studentData[i]);
	}

	cout << "Commands" << endl;
	cout << left << setw(16) << "q: Quit";
	cout << left << setw(20) << "p: Print Options";
	cout << left << setw(20) << "a: Add Student";
	cout << left << setw(20) << "r: Remove Student";
	cout << left << setw(20) << "h: Commands";
	cout << endl;

	while (userInput != "q") {
		//get user input to execute commands
		cin >> userInput;
		recognizedInput = false;
		// set input to lowercase to avoid case sensitive issues
		for (i = 0; i < userInput.length(); i++) {
			if (isupper(userInput.at(i))) userInput.at(i) = tolower(userInput.at(i));
		}

		// print menu/commands
		if (userInput == "p") {
			recognizedInput = true;
			cout << left << setw(18) << "a: All Students";
			cout << left << setw(20) << "d: By Degree";
			cout << left << setw(20) << "e: Invalid Emails";
			cout << left << setw(25) << "c: Average Course Days";
			cout << left << setw(20) << "x: Cancel";
			cout << endl;
			cin >> userInput;
			if (userInput == "a") classRoster->printAll();
			else if (userInput == "d") {
				cout << "Enter a Degree Type (UNDECLARED/SECURITY/NETWORK/SOFTWARE): ";
				cin >> userInput;
				for (int y = 0; y < userInput.length(); y++) {
					if (islower(userInput.at(y))) userInput.at(y) = toupper(userInput.at(y));
				}
				if (userInput == "UNDECLARED") degree = UNDECLARED;
				else if (userInput == "SECURITY") degree = SECURITY;
				else if (userInput == "NETWORK") degree = NETWORK;
				else if (userInput == "SOFTWARE")degree = SOFTWARE;
				else {
					cerr << "ERROR! Invalid Degree Type";
					exit(-1);
				}

				classRoster->printByDegreeProgram(degree);
			}
			else if (userInput == "c") {
				cout << "Enter a Student ID: ";
				cin >> userInput;
				for (int y = 0; y < userInput.length(); y++) {
					if (islower(userInput.at(y))) userInput.at(y) = toupper(userInput.at(y));
				}
				classRoster->printAverageDaysInCourse(userInput);
			}
			else if (userInput == "e") {
				classRoster->printInvalidEmails();
			}
			else if (userInput != "x"){
				cout << "Input Not Recognized" << endl;
				userInput = "x";
			}
			if (userInput == "x") userInput = "h";
		}
		// remove student option
		else if (userInput == "r") {
			cout << "Enter ID to remove: ";
			cin >> userInput;
			for (i = 0; i < userInput.length(); i++) {
				if (islower(userInput.at(i))) userInput.at(i) = toupper(userInput.at(i));
			}
			if (classRoster->removeStudent(userInput)) classRoster->printAll();
			else cout << userInput << ": Student ID Not Found" << endl;
			recognizedInput = true;
		}
		// add student
		else if (userInput == "a") {
			// Expects comma sepearted single line, this could be better
			cout << "Student Data: ";
			cin >> userInput;
			classRoster->parseUserInputAndAdd(userInput);
			cout << "Student Added" << endl;
			recognizedInput = true;
		}

		// print main commands again
		if (userInput == "h") {
			cout << left << setw(16) << "q: Quit";
			cout << left << setw(20) << "p: Print Options";
			cout << left << setw(20) << "a: Add Student";
			cout << left << setw(20) << "r: Remove Student";
			cout << left << setw(20) << "h: Commands";
			cout << endl;
			recognizedInput = true;
		}

		// catch any inputs not recognized and prompt the user
		if (!recognizedInput && userInput != "q") {
			cout << "Input not recognized, please refer to the Commands for valid inputs" << endl;
		}
	}
	return 0;
}
