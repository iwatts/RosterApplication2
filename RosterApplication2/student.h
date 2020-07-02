#pragma once
#include <iostream>
using namespace std;

#include "degree.h"

class student
{
public:
	void getStudentByID(string studentID) {}

	void setStudentFirstName() {}
	void setStudentLastName() {}
	void setStudentEmail() {}
	void setStudentAge() {}
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	int courseDays[3];
	DegreeProgram degree;
};

