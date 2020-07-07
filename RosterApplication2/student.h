#pragma once
#include <iostream>
#include <string>
; using namespace std;

#include "degree.h"
;
class Student
{
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	DegreeProgram degree;

public:
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		string degreeprogram
	);

	//getters
	string getStudentID();

	//setters
	void setStudentID(string studentID);

	virtual DegreeProgram getDegreeProgram() = 0;

	virtual void print() = 0;

	~Student();
};

