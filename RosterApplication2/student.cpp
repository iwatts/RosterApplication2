#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	this->degree = SOFTWARE;
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
	DegreeProgram degreeprogram
) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->degree = degreeprogram;
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

}

Student::~Student() {

}