#include <iostream>
#include <string>
#include "networkStudent.h"
#include "student.h"

using namespace std;


NetworkStudent::NetworkStudent() :Student() {

	degree = DegreeType::NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int num_days[], DegreeType degree) 
	: Student(studentID, firstName, lastName, emailAddress, age, num_days)
{

	degree = DegreeType::NETWORK;
}

DegreeType NetworkStudent::getDegreeProgram() {

	return DegreeType::NETWORK;
}

void NetworkStudent::print() {

	this->Student::print();
	cout << DegreeTypeStrings[1] << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();


}
