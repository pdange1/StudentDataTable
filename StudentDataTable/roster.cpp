#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "roster.h"
#include "degree.h"

using namespace std;

//Parse through strings to build student data table Using a string parcer.

//identify student

//assign student type

//add to roster.



void main() {

    int numStudents = 5;

    const string studentData[] =

    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Peter,D'Angelo,pdange1@wgu.edu,28,48,48,62,SOFTWARE"
    };


   
//F.  Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:

//1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.

//2.  Create an instance of the Roster class called classRoster.

//3.  Add each student to classRoster.

//4.  Convert the following pseudo code to complete the rest of the main() function:
classRoster.printAll();
classRoster.printInvalidEmails();
loop through classRosterArray and for each element:
classRoster.printAverageDaysInCourse(/*current_object's student id*/);
classRoster.printByDegreeProgram(SOFTWARE);
classRoster.remove("A3");
classRoster.remove("A3");
//expected: the above line should print a message saying such a student with this ID was not found.

//5.  Call the destructor to release the Roster memory.


    return;
}