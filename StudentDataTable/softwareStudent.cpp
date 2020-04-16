#include <iostream>
#include <string>
#include "softwareStudent.h"
#include "student.h"


using namespace std;


SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType d) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = d;
}

DegreeType SoftwareStudent::getDegreeProgram() {

	return degree;
}

void SoftwareStudent::print() {

	cout << getStudentID();
	cout << "\t" << "First Name: " << getFirstName();
	cout << "\t" << "Last Name: " << getLastName();
	cout << "\t" << getAge();
	cout << "\t" << "Days in course: {" << getNumDays()[0] << "," << getNumDays()[1] << "," << getNumDays()[2] << "}\t";
	cout << DegreeTypeStrings[2] << endl;
}

