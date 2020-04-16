#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include <iostream>
#include <string>
#include "student.h"

class NetworkStudent : public Student { //inherits from superclass Student.h

public:

		NetworkStudent
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
