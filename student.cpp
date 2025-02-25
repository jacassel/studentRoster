#include <iostream>
#include <string>

#include "student.h"
using namespace std;

Student::Student(string si, string fn, string ln, string em, int a, int _daysToComplete[3], degreeProgram p)
{
	studentID = si;
	firstName = fn;
	lastName = ln;
	email = em;
	age = a;
		for (int i = 0; i < 3; i++) {
			daysToComplete[i] = _daysToComplete[i];
		}
	program = p;
}


Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = -1;
	daysToComplete[0] = -1;
	daysToComplete[1] = -1;
	daysToComplete[2] = -1;
	program = SECURITY;
}

Student::~Student()
{

}

void Student::setStudentID(string ssi)
{
	studentID = ssi;
}

void Student::setFirstName(string sfn)
{
	firstName = sfn;
}

void Student::setLastName(string sln)
{
	lastName = sln;
}

void Student::setEmail(string se)
{
	email = se;
}

void Student::setAge(int sa)
{
	age = sa;
}

void Student::setDaysToComplete(int x, int y, int z)
{
	daysToComplete[0] = x;
	daysToComplete[1] = y;
	daysToComplete[2] = z;
}

void Student::setProgram(degreeProgram x)
{
	program = x;
}

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

const int* Student::getDaysToComplete() const
{
	return daysToComplete;
}

degreeProgram Student::getProgram()
{
	return program;
}

string Student::convertDegreeToString(degreeProgram)
{
	string degreePrograms[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	string DegreeProgram = degreePrograms[getProgram()];
	return DegreeProgram;
}

void Student::print()
{
	cout << getStudentID() << "\t" << getFirstName() << "\t" << getLastName() << "\t"
		<< getAge() << "\t";

	const int* days = getDaysToComplete();
	cout << "{" << days[0] << ", " << days[1] << ", " << days[2] << "}" << "\t";
	cout << convertDegreeToString(getProgram()) << endl;
}

