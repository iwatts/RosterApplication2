#include <string>
#include <iostream>
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
void roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeprogram) {
	//generated ID, the rest is from the user
	student* newStudent = new student;
	studentsInRoster;
}
void roster::remove(string studentID) {
	cout << "Removing: " << studentID << endl;
}
void roster::printAverageDaysInCourse(string studentID) {}
void roster::printByDegreeProgram(enum DegreeProgram degreeprogram) {}
void roster::printInvalidEmails() {
	cout << "print invalid emails" << endl;
	return;
}

roster::roster() {
	int i;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
	};

	for (i = 0; i < 4; i++) {
		studentData[i];
		//this->add(parsedStudent);
	}
}