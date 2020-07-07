#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

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
		DegreeProgram degreeprogram
	);

	//getters
	string getStudentID();
	DegreeProgram getStudentDegree();

	//setters
	void setStudentID(string studentID);
	void setStudentDegree(DegreeProgram degree);

	void print();

	~Student();
};

