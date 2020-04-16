#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYTUDENT_H
#include <iostream>
#include <string>
#include "student.h"

class SecurityStudent : public Student { //inherits from superclass Student.h

public:

	SecurityStudent
	(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int num_days[],
		DegreeType degree
	);

	DegreeType getDegreeProgram();
	void print();

private: 
	DegreeType degree; // refers to degree.h for enum data type to get degree.


};

#endif

