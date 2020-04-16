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
            degree = DegreeType::SOFTWARE;
        }

        else if (row.substr(row.length() - 7, 7) == "NETWORK") {
            degree = DegreeType::NETWORK;
        }

        else if (row.substr(row.length() - 8, 8) == "SECURITY") {
            degree = DegreeType::SECURITY;
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
        lhs = rhs + 1;
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
    if (degree == DegreeType::NETWORK) {
        classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
    }
   else if (degree == DegreeType::SECURITY) {
       classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
   }
    else if (degree == DegreeType::SOFTWARE) {
        classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDays, degree);
    }
    

}

//Remove student ID from roster.
bool Roster::remove(string studentID) {
    cout << "Searching for student " << studentID << "...";
    bool found = false;
    
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;

            cout << "Student " << studentID << " found. Removing student " << this->classRosterArray[i]->getStudentID() << "." << endl;
            //delete
            delete this->classRosterArray[i];
            //Assign last book to current position.
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
            break;
        }
       else {
            found = false;
            
       }
    }
    if (found == false) {
        cout << "Student Not Found." << endl;
    }
    return found;
}

//Print all students on roster.
void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) { //loop through each student in roster via last index and print all info.
        (this->classRosterArray)[i]->print();
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
            string email = classRosterArray[i]->getEmailAddress();
            if ((email.find('@') == string::npos) || (email.find(' ') != string::npos) || (email.find('.')) == string::npos) {
                cout << "The student email: " << classRosterArray[i]->getEmailAddress() <<  " for " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is invalid.\n";
            }
            else {
                cout << "The student email: " << classRosterArray[i]->getEmailAddress() << " for " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is valid.\n";
            }
    }
}
void Roster::printAverageDaysInCourse(string studentID) {

    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            int* days = classRosterArray[i]->getNumDays();
            cout << "Average number of days left in course " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << endl;

        }

    }

}

void Roster::printByDegreeProgram(int d) {
    cout << "Printing students of type " << DegreeTypeStrings[d] << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == d) {
            this->classRosterArray[i]->print();
        }
    }
}

Roster::~Roster()
{
    for (int i = 0; i <= lastIndex; i++) {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
}



//F.  Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:
    int main() {

        /*1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.*/
        cout << endl << endl << endl;
        cout << "     ---===|     Course Title     |===---" << endl;
        cout << "Scripting and Programming - Applications: C867" << endl << endl;
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

        cout << "DISPLAYING ALL STUDENTS ON ROSTER." << endl << endl;

            classRoster->printAll();
            cout << endl;


        /*verifies student email addresses and displays all invalid email addresses to the user
        Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').*/
        //Displaying invalid Emails
        classRoster->printInvalidEmails();
        cout << endl;
       
        //loop through classRosterArray and for each element:
        cout << "AVERAGE COURSE DAYS" << endl;
        for (int i = 0; i < numStudents; i++) {
            classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
        }
        cout << endl;
        classRoster->printByDegreeProgram(SOFTWARE);

        classRoster->remove("A3");
        cout << endl;
        classRoster->remove("A3");
        cout << endl;
        //expected: the above line should print a message saying such a student with this ID was not found.



        //5.  Call the destructor to release the Roster memory.
       
        system("pause");

        classRoster->~Roster();

        return 0;
    };