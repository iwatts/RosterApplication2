#include <string>
#include <iostream>
#include <vector>
#include <regex>
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
		// put the days in course into an array
		int daysInCourseList[3];
		daysInCourseList[0] = daysInCourse1;
		daysInCourseList[1] = daysInCourse2;
		daysInCourseList[2] = daysInCourse3;

		addStudent(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourseList,
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
	int daysInCourseList[],
	DegreeProgram degree
) {
	// add the new student to the end of the students array
	students[lastIndex] = new Student(
		studentID,
		firstName,
		lastName,
		emailAddress,
		age,
		daysInCourseList,
		degree
	);
}
bool Roster::removeStudent(string studentID) {
	bool found = false;
	string confirmationInput = "";
	cout << "Removing: " << studentID << endl;
	for (int i = 0; i <= this->lastIndex; i++) {
		if (this->students[i]->getStudentID() == studentID) {
			found = true;
			this->students[i]->print();

			//confirm deletion before removing
			cout << "Confirm Deletion (Y/N): ";
			cin >> confirmationInput;
			for (int y = 0; y < confirmationInput.length(); y++) {
				if (isupper(confirmationInput.at(y))) confirmationInput.at(y) = tolower(confirmationInput.at(y));
			}
			if (confirmationInput == "y") {
				// only delete if "y"
				delete this->students[i];
				this->students[i] = this->students[lastIndex];
				lastIndex--;
				cout << studentID << " Removed" << endl;
			}
			else {
				cout << "Canceled" << endl;
			}
		}
	}

	return found;
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->students)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= this->lastIndex; i++) {
		if (this->students[i]->getStudentID() == studentID) {
			found = true;
			int* days = students[i]->getStudentDaysInCourse();
			this->students[i]->print();
			cout << "Average days in course: " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
	if (!found) cout << "Student ID not Found" << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (int i = 0; i <= this->lastIndex; i++) {
		if (this->students[i]->getStudentDegree() == degreeprogram) {
			this->students[i]->print();
		}
	}
}
void Roster::printInvalidEmails() {
	bool any = false;
	cout << "Invalid Emails: " << endl;
	for (int i = 0; i <= this->lastIndex; i++) {
		string email = students[i]->getStudentEmail();
		// use regex to check if email matches valid patterns
		if (!regex_match(email, regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"))) {
			any = true;
			cout << students[i]->getStudentEmail() << endl;
		}
	}
	if (!any) cout << "None" << endl;
}


Roster::~Roster() {
	for (int i = 0; i <= this->lastIndex; i++) {
		delete this->students[i];
	}
	delete students;
}