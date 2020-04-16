
#include <iostream>
#include <string>
#include "securityStudent.h"
#include "student.h"





using namespace std;


	SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType d)
		: Student(studentID, firstName, lastName, emailAddress, age, num_days)
	{
		degree = d;
	}

	DegreeType SecurityStudent::getDegreeProgram() {

		return degree;
	}

	void SecurityStudent::print() {

		cout << getStudentID();
		cout << "\t" << "First Name: " << getFirstName();
		cout << "\t" << "Last Name: " << getLastName();
		cout << "\t" << getAge();
		cout << "\t" << "Days in course: {" << getNumDays()[0] << "," << getNumDays()[1] << "," << getNumDays()[2] << "}\t";
		cout << DegreeTypeStrings[0] << endl;
	}

