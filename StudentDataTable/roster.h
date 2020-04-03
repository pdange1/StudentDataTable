//HEADER FILE TEMPLATE
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "student.h"

using namespace std;

const int numStudents = 5;

const string studentData[numStudents] = {

    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Peter,D'Angelo,pdange1@wgu.edu,28,48,48,62,SOFTWARE"
};

//Stores roster of students.
class Roster {
private:
    int size;                       //Max number of students in the roster
    int lastIndex;                  //Index of student in the roster.
    Student** classRosterArray;     //Array of pointers to student.
public:
    Roster();
    Roster(int size); // Sets max size of roster.

    Student* getStudentAt(int index);
    void parser(string stringRowData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree);
    bool remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeType degree);

};


#endif
