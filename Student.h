//Header Guard
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;
//Student Class
class Student{
public:
//Variables
char firstName[100];
char lastName[100];
int ID;
float GPA;
//Constructor
Student();
//Destructor
~Student();
//Set GPA
int getID();
float getGPA();
//Return the Student's name
char* getFirstName();
};

#endif