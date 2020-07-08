#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "roster.h"
#include "degree.h"
#include "student.h"

Roster::Roster() {
	//studentsInRoster vector - empty
	this->capacity = 0;
	this->students = nullptr;
}

void Roster::printAll() {
	cout << "Print All" << endl;
	return;
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
	string degreeprogram
) {
	// add the new student to the studentsInRoster vector
}
bool Roster::remove(string studentID) {
	cout << "Removing: " << studentID << endl;
}
void Roster::printAverageDaysInCourse(string studentID) {}
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {}
void Roster::printInvalidEmails() {
	cout << "Print invalid emails" << endl;
	return;
}



Roster::~Roster() {

}