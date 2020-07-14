#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
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
		DegreeProgram degree
	);

	//getters
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getStudentAge();
	DegreeProgram getStudentDegree();

	//setters
	void setStudentID(string studentID);
	void getStudentFirstName(string firstName);
	void getStudentLastName(string lastName);
	void setStudentEmail(string email);
	void setStudentEmail(int age);
	void setStudentDegree(DegreeProgram degree);

	void print();

	~Student();
};

