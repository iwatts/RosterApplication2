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

	cout << left << setw(16) << "q: Quit";
	cout << left << setw(20) << "p: Print Options";
	cout << left << setw(20) << "a: Add Student";
	cout << left << setw(20) << "r: Remove Student";
	cout << left << setw(20) << "h: Commands";
	cout << endl;
	classRoster->printAll();

	while (true) {
		cout << "Enter Command (H=Help): ";
		cin >> userInput;
		char formattedInput = toupper(userInput[0]);

		switch (formattedInput) {
		case 'H':
			cout << left << setw(16) << "q: Quit";
			cout << left << setw(20) << "p: Print Options";
			cout << left << setw(20) << "a: Add Student";
			cout << left << setw(20) << "r: Remove Student";
			cout << left << setw(20) << "h: Commands";
			cout << endl;
			break;
		case 'Q':
			return 0;
		case 'P':
			cout << left << setw(18) << "a: All Students";
			cout << left << setw(20) << "d: By Degree";
			cout << left << setw(20) << "e: Invalid Emails";
			cout << left << setw(25) << "c: Average Course Days";
			cout << left << setw(20) << "x: Cancel";
			cout << endl;
			cin >> userInput;

			switch (toupper((char)userInput.substr(0, 1).c_str())) {
			case 'A':
				classRoster->printAll();
				break;
			case 'D':
				cout << "Enter a Degree Type" << endl;
				cout << "  1=UNDECLARED" << endl;
				cout << "  2=SECURITY" << endl;
				cout << "  3=NETWORK" << endl;
				cout << "  4=SOFTWARE" << endl;
				cout << "Enter choice (q=quit): ";
				cin >> userInput;
				switch (toupper((char)userInput.substr(0, 1).c_str())) {
				case '1':
					classRoster->printByDegreeProgram(UNDECLARED);
					break;
				case '2':
					classRoster->printByDegreeProgram(SECURITY);
					break;
				case '3':
					classRoster->printByDegreeProgram(NETWORK);
					break;
				case '4':
					classRoster->printByDegreeProgram(SOFTWARE);
					break;
				default:
					break;
				}
				break;
			case 'C':
				cout << "Enter a Student ID: ";
				cin >> userInput;
				for (int y = 0; y < userInput.length(); y++) {
					if (islower(userInput.at(y))) userInput.at(y) = toupper(userInput.at(y));
				}
				classRoster->printAverageDaysInCourse(userInput);
				break;
			case 'E':
				classRoster->printInvalidEmails();
				break;
			default:
				break;
			}
			break;
		case 'R':
			// remove student option
			cout << "Enter ID to remove: ";
			cin >> userInput;
			for (i = 0; i < userInput.length(); i++) {
				if (islower(userInput.at(i))) userInput.at(i) = toupper(userInput.at(i));
			}
			if (classRoster->removeStudent(userInput)) {
				classRoster->printAll();
			}
			else {
				cout << userInput << ": Student ID Not Found" << endl;
			}
			break;
		case 'A':
			// add student
			// Expects comma separated single line, this could be better
			cout << "Student Data: ";
			cin >> userInput;
			classRoster->parseUserInputAndAdd(userInput);
			cout << "Student Added" << endl;
			break;
		default:
			cout << "\"" << formattedInput << "\"";
			cout << "Input not recognized, please refer to the Commands for valid inputs" << endl;
		}
	}
	return 0;

}
