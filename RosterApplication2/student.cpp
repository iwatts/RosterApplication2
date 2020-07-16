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
	for (int i = 0; i < this->daysInCourseSize; i++) this->daysInCourseList[i] = 0;
	this->degree = UNDECLARED;
}

Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourseList[],
	DegreeProgram degree
) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < this->daysInCourseSize; i++) this->daysInCourseList[i] = daysInCourseList[i];
	this->degree = degree;
}

//getters
string Student::getStudentID() {
	return studentID;
}
string Student::getStudentFirstName() {
	return firstName;
}
string Student::getStudentLastName() {
	return lastName;
}
string Student::getStudentEmail() {
	return emailAddress;
}
int Student::getStudentAge() {
	return age;
}
int* Student::getStudentDaysInCourse() {
	return daysInCourseList;
}
DegreeProgram Student::getStudentDegree() {
	return degree;
}

//setters
void Student::setStudentID(string ID) {
	studentID = ID;
}
void Student::setStudentFirstName(string f) {
	firstName = f;
}
void Student::setStudentLastName(string l) {
	lastName = l;
}
void Student::setStudentEmail(string email) {
	emailAddress = email;
}
void Student::setStudentAge(int a) {
	age = a;
}
void Student::setStudentDaysInCourse(int days[]) {
	for (int i = 0; i < this->daysInCourseSize; i++) this->daysInCourseList[i] = days[i];
}
void Student::setStudentDegree(DegreeProgram d) {
	degree = d;
}

void Student::print() {
	cout << left << setw(4) << studentID;
	cout << left << setw(15) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(8) << age;
	cout << left << setw(5) << daysInCourseList[0];
	cout << left << setw(5) << daysInCourseList[1];
	cout << left << setw(5) << daysInCourseList[2];
	cout << left << setw(10) << degreeProgramStrings[degree];
	cout << endl;
}

Student::~Student() {

}