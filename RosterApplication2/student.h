#pragma once
#include <iostream>
using namespace std;

#include "degree.h"

class student
{
public:
	void getStudentByID(string studentID) {}
	void removeStudentByID(string studentID) {}
	void setStudent() {}

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	enum DegreeProgram degree;
};

