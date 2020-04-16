#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"


using namespace std;

Student::Student() { //Will set default values via empty/default constructor.

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this-> age = 0;
	for (int i = 0; i < dayArraySize; i++) {
		this->num_days[i] = 0;
	}

}

Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int num_days[]) { //assigns values to internal variables.

	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) {
		this->num_days[i] = num_days[i];
	}
	
}


//getter i.e. accessor functions.  Creates empty placeholders for object parameters
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getNumDays() {
	return num_days;
}

//setter i.e mutator functions. Sets values to previous empty placeholders creating a new object. 

void Student::setStudentID(string ID) {
	studentID = ID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDays(int num_days[]) {
	for (int i = 0; i < dayArraySize; i++) {
		this->num_days[i] = num_days[i];
	}
}


Student::~Student() {

}