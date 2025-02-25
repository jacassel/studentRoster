#include <iostream>
#include <string>

#include "roster.h"
using namespace std;

int main() {
	const string studentData[] = {

"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Joel,Cassel,jca2590@wgu.edu,23,28,32,53,SOFTWARE"

	};
	cout << "C867 Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 011777693" << endl;
	cout << "Name: Joel Cassel" << endl << endl;
	Roster classRoster;
	for (int i = 0; i <= 4; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	classRoster.printInvalidEmails();
	cout << "Displaying average days in course: " << endl << endl;
	for (int i = 0; i < classRoster.lastStudentIndex; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i] -> getStudentID());
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	
	cout << "DONE." << endl;
	cout << endl;
	return 0;
}