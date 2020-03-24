#ifndef SECURITYSTUDENT_H
#define SECURITYTUDENT_H
#include <string>
#include "student.h"

class SecurityStudent : public Student { //inherits from superclass Student.h

public:
	SecurityStudent();
	SecurityStudent
	(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* num_days[],
		DegreeType degree
	);

	DegreeType getDegreeProgram();
	void print();

	~SecurityStudent();
};

#endif