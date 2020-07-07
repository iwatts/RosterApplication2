#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "roster.h"
#include "degree.h"
#include "student.h"

void roster::printAll() {
	cout << "Print All" << endl;
	return;
}
void roster::printStudent(string studentID) {

}
void roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram) {
	// add the new student to the studentsInRoster vector
	student* newStudent = new student;
	// roster::studentsInRoster.push_back(newStudent);
}
void roster::remove(string studentID) {
	cout << "Removing: " << studentID << endl;
}
void roster::printAverageDaysInCourse(string studentID) {}
void roster::printByDegreeProgram(DegreeProgram degreeprogram) {}
void roster::printInvalidEmails() {
	cout << "Print invalid emails" << endl;
	return;
}

roster::roster() {}