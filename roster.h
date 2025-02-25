#pragma once
#include <iostream>
#include <string>

#include "student.h"
using namespace std;

class Roster
{
private:
	

public: 
	int lastStudentIndex;
	Student* classRosterArray[5];
	Roster();
	~Roster();
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string email, int age, 
		int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degreeProgram studentDegreeProgram);
};


