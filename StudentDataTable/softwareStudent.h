#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include <iostream>
#include <string>
#include "student.h"

class SoftwareStudent : public Student { //inherits from superclass Student.h

public:

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

private:
	DegreeType degree;// refers to degree.h for enum data type to get degree.
};

#endif