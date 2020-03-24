//HEADER FILE TEMPLATE
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"

using namespace std;


//Stores roster of students.
class Roster {

private:
    int size;               //Max number of students in the roster
    int lastIndex;          //Index of final student in the roster.
    Student** students;     //Array of pointers to students. 

public:
    Roster();
    Roster(int size);
};

#endif
#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

using namespace std;

//Parse through strings to build student data table Using a string parcer.

//identify student

//assign student type


//F.  Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:

//1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.

//2.  Create an instance of the Roster class called classRoster.

//3.  Add each student to classRoster.

//4.  Convert the following pseudo code to complete the rest of the main() function:
/*
classRoster.printAll();
classRoster.printInvalidEmails();
loop through classRosterArray and for each element:
classRoster.printAverageDaysInCourse(//current_object's student id);
classRoster.printByDegreeProgram(SOFTWARE);
classRoster.remove("A3");
classRoster.remove("A3");
*/
//expected: the above line should print a message saying such a student with this ID was not found.

//5.  Call the destructor to release the Roster memory.
