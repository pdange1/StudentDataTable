#include "securityStudent.h"
#include "student.h"




using namespace std;



SecurityStudent::SecurityStudent() :Student() {

	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType degree) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = SECURITY;
}

DegreeType SecurityStudent::getDegreeProgram() {

	return SECURITY;
}

void SecurityStudent::print() {

	this->Student::print();
	cout << DegreeTypeStrings[0] << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();


}