#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class roster
{
public:
	void printAll();
	void printStudent(string studentID);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
};

