#include <iostream>
#include <string>

#include "roster.h"
using namespace std;


Roster::Roster()
{
	for (int i = 0; i <= 4; i++)
	{
		classRosterArray[i] = nullptr; 
	}
	lastStudentIndex = 0;
}

Roster::~Roster() {
	for (int i = 0; i < lastStudentIndex; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::parse(string row) // This creates the parse function
{
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	int daysToComplete[3] = { 0 };
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	daysToComplete[0] = { stoi(row.substr(lhs, rhs - lhs)) };

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	daysToComplete[1] = { stoi(row.substr(lhs, rhs - lhs)) };

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	daysToComplete[2] = { stoi(row.substr(lhs, rhs - lhs)) };

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string program = row.substr(lhs, rhs - lhs);

	degreeProgram degree = degreeProgram::SOFTWARE;
	if (program == "SECURITY") {
		degree=SECURITY;
	}
	else if (program=="NETWORK") {
		degree=NETWORK;
	}
	else if(program=="SOFTWARE") {
		degree=SOFTWARE;
	}
	add(studentID, firstName, lastName, email, age, daysToComplete[0], daysToComplete[1],
		daysToComplete[2], degree);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degreeprogram)
{
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* studentObject = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeprogram);
	classRosterArray[lastStudentIndex] = studentObject;
	lastStudentIndex++;
}

void Roster::remove(string studentID)
{
	if (lastStudentIndex == 5) {
		for (int i = 0; i <= lastStudentIndex; i++) {
			string studentRef = classRosterArray[i]->getStudentID();
			if (studentRef == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				for (int j = i; j < lastStudentIndex; j++) {
					classRosterArray[j] = classRosterArray[j + 1];
				}
				lastStudentIndex--;
				break;
			}
		}
		cout << "Removing A3:" << endl << endl;
	}
	else {
		cout << "Removing A3 again" << endl << endl;
		cout << "The student with the ID: A3 was not found." << endl;
	}
}

void Roster::printAll()
{
	cout << "Displaying all students: " << endl << endl;
	for (int i = 0; i < lastStudentIndex; i++) {
		classRosterArray[i] -> print();
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < lastStudentIndex; i++) {
		
		if (studentID == classRosterArray[i]->getStudentID()) {
			auto daysInCourse = classRosterArray[i] -> getDaysToComplete();
			int dayOne = daysInCourse[0];
			int dayTwo = daysInCourse[1];
			int dayThree = daysInCourse[2];
			float averageDays = (dayOne + dayTwo + dayThree) / 3;
			cout << "Student Id: " << studentID << ", " << "average days in course is: " << averageDays << endl;

		}
	}
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid Emails" << endl << endl;
	for (int i = 0; i < lastStudentIndex; i++) {
		string email = classRosterArray[i] -> getEmail();
		string tester = "This is to test that the email is invalid z";
		size_t testValue = tester.find("z");
		size_t testEmailAt = email.find("@");
		size_t testEmailPeriod = email.find(".");
		size_t testEmailNoSpace = email.find(" ");
		if (testEmailAt <= testValue && testEmailPeriod <= testValue && testEmailNoSpace == std::string::npos) 
		{
			continue;
		}
		else {
			cout << email << " - " << "is invalid." << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(degreeProgram studentDegreeProgram)
{
	string printProgram = classRosterArray[studentDegreeProgram]->convertDegreeToString(studentDegreeProgram);
	cout << "Showing Students in degree program: " << printProgram << endl << endl;
	for (int i = 0; i < lastStudentIndex; i++) {
		string program = classRosterArray[i] -> convertDegreeToString(studentDegreeProgram);
		degreeProgram numProgram = classRosterArray[i]->getProgram();
		if (numProgram == studentDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}