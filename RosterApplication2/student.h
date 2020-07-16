#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class Student
{
public:
	const static int daysInCourseSize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourseList[daysInCourseSize];
	DegreeProgram degree;

public:
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourseList[],
		DegreeProgram degree
	);

	//getters
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getStudentAge();
	int* getStudentDaysInCourse();
	DegreeProgram getStudentDegree();

	//setters
	void setStudentID(string studentID);
	void setStudentFirstName(string firstName);
	void setStudentLastName(string lastName);
	void setStudentEmail(string email);
	void setStudentAge(int age);
	void setStudentDaysInCourse(int daysInCourseList[]);
	void setStudentDegree(DegreeProgram degree);

	void print();

	~Student();
};

