#include <string>
#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse1 = 0;
	this->daysInCourse2 = 0;
	this->daysInCourse3 = 0;
	this->degree = UNDECLARED;
}

Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degree
) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->degree = degree;
}

//getters
string Student::getStudentID() {
	return studentID;
}
DegreeProgram Student::getStudentDegree() {
	return degree;
}

//setters
void Student::setStudentID(string ID) {
	studentID = ID;
}
void Student::setStudentDegree(DegreeProgram d) {
	degree = d;
}

void Student::print() {
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(10) << emailAddress;
}

Student::~Student() {

}