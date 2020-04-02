#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {  
public:
    const static int dayArraySize = 3; //size of array holding remaining course days. 

   protected:                          //These items are visible to derived classes.
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int    age;
        int    num_days[dayArraySize];   //array of number of days remaining in courses referencing const dayArraySize.
        DegreeType degree;            // refers to degree.h for enum data type to get degree.
        

   public:
       Student();
       Student
       (
           string ID, 
           string firstName, 
           string lastName, 
           string eAddress, 
           int Age, 
           int num_days[], 
           DegreeType degree
       );

       //getters i.e.. accessor for student.cpp

       string getStudentID();
       string getFirstName();
       string getLastName();
       string getEmailAddress();
       int    getAge();
       int*   getNumDays();
       virtual DegreeType getDegreeProgram() = 0;

       //setters i.e.. mutators for student.cpp

       void setStudentID(string ID);
       void setFirstName(string firstName);
       void setLastName(string lastName);
       void setEmailAddress(string eAddress);
       void setAge(int age);
       void setNumDays(int num_days[]);

       virtual void setDegreeProgram(DegreeType degree) = 0;
       virtual void print() = 0; //Virtual method used to print object info to to command prompt.




//Destructor
~Student();

};

#endif