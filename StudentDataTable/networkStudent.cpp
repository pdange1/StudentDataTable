#include "networkStudent.h"
#include "student.h"

#include <iostream>;


using namespace std;


NetworkStudent::NetworkStudent() :Student() {

	degree = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType degree) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = NETWORK;
}

DegreeType NetworkStudent::getDegreeProgram() {

	return NETWORK;
}

void NetworkStudent::print() {

	this->Student::print();
	cout << DegreeTypeStrings[1] << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();


}
