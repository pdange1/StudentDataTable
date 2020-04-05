#include "softwareStudent.h"
#include "student.h"


using namespace std;


SoftwareStudent::SoftwareStudent() :Student() {

	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType degree) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeProgram() {

	return SOFTWARE;
}

void SoftwareStudent::print() {

	this->Student::print();
	cout << DegreeTypeStrings[2] << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();


}
