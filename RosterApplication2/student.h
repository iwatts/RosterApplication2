#pragma once
#include <iostream>
using namespace std;

#include "degree.h"

class student
{
public:
	void getStudentByID(string studentID) {}
	void setStudentByID(string studentID) {}
	void removeStudentByID(string studentID) {}
	void print(string studentID) {}

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	// enum DegreeProgram degree;
};

