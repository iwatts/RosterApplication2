#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "degree.h"
#include "student.h"

class roster
{
public:
	void printAll();
	void printStudent(string studentID);
	void addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, enum DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmails();
	roster();

private:
	vector<student> studentsInRoster;
	student newStudent;
};

