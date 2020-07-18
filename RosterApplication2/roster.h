#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "degree.h"
#include "student.h"

class Roster
{
private:
	int capacity; // need a limit on the number of students
	int lastIndex;
	Student** students;
public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);

	// parse out the input before adding
	void parseUserInputAndAdd(string userData);

	// only run on successful parsing
	void addStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourseList[],
		DegreeProgram degreeProgram
	);
	bool removeStudent(string studentID);

	// Printing options
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmails();

	~Roster();
};

