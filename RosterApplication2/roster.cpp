#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

void roster::printAll() {
	cout << "Print All" << endl;
	return;
}
void roster::printStudent(string studentID) {}
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {}
void roster::remove(string studentID) {
	cout << "Removing: " << studentID << endl;
}
void roster::printAverageDaysInCourse(string studentID) {}
void roster::printInvalidEmails() {
	cout << "print invalid emails" << endl;
	return;
}