#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include <iostream>
#include <string>
#include "student.h"

class SoftwareStudent : public Student { //inherits from superclass Student.h

public:
	SoftwareStudent();
	SoftwareStudent
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

	~SoftwareStudent();
};

#endif