#pragma once
#include <iostream>
#include <string>
#include <array>

#include "degree.h"
using namespace std;

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	degreeProgram program;

public:
	Student(string, string, string, string, int, int[3], degreeProgram);
	Student();
	~Student();

	string DegreeProgram = "";
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysToComplete(int, int, int);
	void setProgram(degreeProgram);
	void print();
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	const int* getDaysToComplete() const;
	degreeProgram getProgram();
	string convertDegreeToString(degreeProgram);

};
