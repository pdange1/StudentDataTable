#include <iostream>
#include <string>
#include "networkStudent.h"
#include "student.h"

using namespace std;




NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType d) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = d;
}

DegreeType NetworkStudent::getDegreeProgram() {

	return degree;
}

void NetworkStudent::print() {

	cout << getStudentID();
	cout << "\t" << "First Name: " << getFirstName();
	cout << "\t" << "Last Name: " << getLastName();
	cout << "\t" << getAge();
	cout << "\t" << "Days in course: {" << getNumDays()[0] << "," << getNumDays()[1] << "," << getNumDays()[2] << "}\t";
	cout << DegreeTypeStrings[1] << endl;
}


