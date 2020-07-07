#include <string>
#include <iostream>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
}

//getters
string Student::getStudentID() {
	return studentID;
}

//setters
void Student::setStudentID(string ID) {
	studentID = ID;
}

Student::~Student() {

}