#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "roster.h"
#include "degree.h"

using namespace std;

//Call empty constructor to avoid call by default.
Roster::Roster() { //Sets to default values.
    this->size = 0; //number of items roster can hold.
    this->lastIndex = -1; //means array of pointers is empty. 
    this->classRosterArray = nullptr; //null pointer to fill each call to memory location. 
}

Roster::Roster(int size) { //Sets max size to roster.
    this->size = size;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[size]; //Allocates memory and creates an array of pointers to "size"'s specified size.

}

Student* Roster::getStudentAt(int index) {
    return classRosterArray[index];
}

void Roster::parser(string row) {

    if (lastIndex < size) {
        lastIndex++;
        DegreeType degree;
        if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
            degree = SOFTWARE;
        }

        else if (row.substr(row.length() - 7, 7) == "NETWORK") {
            degree = NETWORK;
        }

        else if (row.substr(row.length() - 8, 8) == "SECURITY") {
            degree = SECURITY;
        }

        else {
            cerr << "INVALID STUDENT TYPE! EXITING NOW" << endl;
            exit(-1);
        };

        //Parcing through roster string to create substrings of information relative to student field.

        //Read Student ID and assign it to a variable.
        int rhs = row.find(",");
        string studentID = row.substr(0, rhs);

        //Read first name of student
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string firstName = row.substr(lhs, rhs - lhs);

        //Read last name of student
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string lastName = row.substr(lhs, rhs - lhs);

        //Read student email address
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string emailAddress = row.substr(lhs, rhs - lhs);

        //Read student age and convert from string to int.
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int age = stoi(row.substr(lhs, rhs - lhs));

        //Read student reamaining class days for class 1 and convert to int.
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

        //Read student reamaining class days for class 2 and convert to int.
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

        //Read student reamaining class days for class 3 and convert to int.
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

        //Read student reamaining class days for class 3 and convert to int.
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

        

        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);


    }
    else {
        cerr << "::ERROR:: \nMAXIMUM CAPACITY REACHED!\n::EXITING::";
        exit(-1);
    }

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree) {

    int numDays[Student::dayArraySize];
    numDays[0] = daysInCourse1;
    numDays[1] = daysInCourse2;
    numDays[2] = daysInCourse3;
    if (degree == NETWORK) {
        classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
    }
    else if (degree == NETWORK) {
        classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
    }
    else if (degree == NETWORK) {
        classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
    }

}

//Remove student ID from roster.
bool Roster::remove(string studentID) {
    bool found = false;
    
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            //delete
            delete this->classRosterArray[i];
            //Assign last book to current position.
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
        else {
            bool found = false;
            cout << "STUDENT NOT FOUND!";
        }
    }
    return found;
}

//Print all students on roster.
void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) { //loop through each student in roster via last index and print all info.
        this->classRosterArray[i]->print();
    }
}

void Roster::printInvalidEmails(string emailAddress) {
    if 
}




//F.  Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:
    void main() {

        /*1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.*/
        cout << "     ---===|     Course Title     |===---" << endl;
        cout << "Scripting and Programming - Applications – C867" << endl << endl;
        cout << "     ---===| Programming Language |===---" << endl;
        cout << "                    C++" << endl << endl;
        cout << "     ---===| Student Name and ID  |===---" << endl;
        cout << "  Student ID: #000983055 Name: Peter D'Angelo" << endl << endl;


        //2.  Create an instance of the Roster class called classRoster.
        Roster* classRoster = new Roster(numStudents);

        //3.  Add each student to classRoster.
        for (int i = 0; i < numStudents; i++) {
            classRoster->parser(studentData[i]);
        }

        cout << "DONE." << endl;
        cout << "DISPLAYING ALL STUDENTS" << endl;
        classRoster->printAll();

        //Displaying invalid Emails
        cout << "INVALID EMAIL ADDRESS" << endl;
        classRoster.printInvalidEmails();
        //loop through classRosterArray and for each element:
        classRoster.printAverageDaysInCourse(/*current_object's student id*/);
        classRoster.printByDegreeProgram(SOFTWARE);
        classRoster.remove("A3");
        classRoster.remove("A3");
        //expected: the above line should print a message saying such a student with this ID was not found.

        5.  Call the destructor to release the Roster memory.


        //4.  Convert the following pseudo code to complete the rest of the main() function:



        //5.  Call the destructor to release the Roster memory.


        return;
    };