#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include <string>
#include "student.h"

class NetworkStudent : public Student { //inherits from superclass Student.h

public:
		NetworkStudent();
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

			~NetworkStudent();
};

#endif
