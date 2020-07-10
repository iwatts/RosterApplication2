#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "roster.h"
#include "degree.h"
#include "student.h"

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capactity) {
	this->capacity = capactity;
	this->lastIndex = -1;
	this->students = new Student * [capacity];
}

Student* Roster::getStudentAt(int index) {
	return students[index];
}

void Roster::parseUserInputAndAdd(string userData) {
	int rhs;
	int lhs;

	if (lastIndex < capacity) {
		lastIndex++;
		DegreeProgram degree = UNDECLARED;

		//Get the ID
		rhs = userData.find(",");
		string studentID = userData.substr(0, rhs);

		//get firstname
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		string firstName = userData.substr(lhs, rhs - lhs);

		//get lastName
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		string lastName = userData.substr(lhs, rhs - lhs);

		//get emailAddress
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		string emailAddress = userData.substr(lhs, rhs - lhs);

		//get age
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		int age = stoi(userData.substr(lhs, rhs - lhs));

		//get daysInCourse1
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		int daysInCourse1 = stoi(userData.substr(lhs, rhs - lhs));

		//get daysInCourse2
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		int daysInCourse2 = stoi(userData.substr(lhs, rhs - lhs));

		//get daysInCourse3
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		int daysInCourse3 = stoi(userData.substr(lhs, rhs - lhs));

		//get degreeProgram
		lhs = rhs + 1;
		rhs = userData.find(",", lhs);
		string degreeProgramString = userData.substr(lhs, rhs - lhs);

		if (degreeProgramString == "UNDECLARED") degree = UNDECLARED;
		else if (degreeProgramString == "SECURITY") degree = SECURITY;
		else if (degreeProgramString == "NETWORK") degree = NETWORK;
		else if (degreeProgramString == "SOFTWARE")degree = SOFTWARE;
		else {
			cerr << "ERROR! Invalid Degree Type";
			exit(-1);
		}

		addStudent(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse1,
			daysInCourse2,
			daysInCourse3,
			degree
		);
	}
	else {
		cerr << "ERROR! Student List is Full";
		exit(-1);
	}
}

void Roster::addStudent(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeProgram
) {
	// add the new student to the studentsInRoster vector
}
bool Roster::remove(string studentID) {
	bool found = false;
	cout << "Removing: " << studentID << endl;
	return found;
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->students)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {}
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {}
void Roster::printInvalidEmails() {
	cout << "Print invalid emails" << endl;
	return;
}


Roster::~Roster() {

}