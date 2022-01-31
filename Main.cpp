/*
This is Student List (Linked Lists edition)! An exercise in making a linked list with the use of another student's Node.cpp and Node.h files.
Author: Jeffrey Teh
Date Completed: 1/30/2022
Thanks to Kyle Zhou and Jayden Huang for helping with this assignment, and to Zayeed Saffat for his code.
*/
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;
//Function prototypes
void add(Node* previous,Node* & head, Node* current, Student* newStudent);
void print(Node* next, Node* &head);
void deleteStudent(Node* current, Node* &head, int id, Node* previous);
void average(Node* head, float sum, int nodeCount);
//Main method
int main(){
Node* head = NULL;
bool playing = true;
//Prompt text
cout <<"Welcome to Student List (Linked Lists edition)! Enter a student into a list by adding their first and lastnames, student ID, and GPA." << endl;
while(playing == true){
//Instruction text
cout << "To add a student, type 'ADD'. To delte a student, type 'DELETE'. To print the list, type 'PRINT'. To print the average GPA of all students, type 'AVERAGE'. To quit, type 'QUIT'." << endl;
char input[10];
//Keep reading in input
cin >> input;
//If the user adds a new student
if(strcmp(input, "ADD") == 0){
    char firstInput[100];
    char lastInput[100];
    int id;
    float GPA;
    //Enter the Student's information
    cout << "You're adding a new student!" << endl;
    cout << "Enter their first name." << endl;
    cin >> firstInput;
    cout << "Enter their lastname." << endl;
    cin >> lastInput;
    cout << "Enter their student ID." << endl;
    cin >> id;
    cout << "Enter their GPA." << endl;
    cin >> GPA;
    Student* s = new Student(firstInput,lastInput,id, GPA);
    //Add the student to the linked list
    add(head, head, head, s);
}
//When the user deltes a student
if(strcmp(input, "DELETE") == 0){
    int input = 0;
    //Entering the ID of the student you're deleting
    cout << "Enter the student ID of the student you're deleting" << endl;
    cin >> input;
    //Delete said student
    deleteStudent(head, head, input, NULL);
}
//If the user prints the list
if(strcmp(input, "PRINT") == 0){
    //Print the list recursively
    print(head, head);
}
//If the user averages the GPAs of the students
if(strcmp(input, "AVERAGE") == 0){
    float sum = 0;
    int nodeCount = 0;
    //Average the GPAs
    average(head, sum, nodeCount);
}
//If the User quits
if(strcmp(input, "QUIT") == 0){
 playing = false;
}
}
}
//Adding a student (This part was done with help from Kyle and Jayden)
void add(Node* previous,Node* & head, Node* current, Student* newStudent){
    //IF the list is empty
    if(head == NULL){
        //Add the student to the head
        head = new Node(newStudent);
    }
    //If the current node is NULL
    else if(current == NULL){
    //Setting the previous nodoe to a new node
    previous->setNext(new Node(newStudent));
    previous->getNext()->setNext(NULL);
    }
    //If the head's student's ID is higher than the new student's ID
    else if(head->getStudent()->getID() > newStudent->getID()){
    Node* temp = head;
    head = new Node(newStudent);
    head->setNext(temp);    
    }
    //If the current student's ID is higher than the new student's ID
    else if(current->getStudent()->getID() > newStudent->getID()){
    previous->setNext(new Node(newStudent));
    previous->getNext()->setNext(current);
    }
    else{
    //Call add again
        add(head, current, current->getNext(), newStudent);
    }
    }
//Print function    
void print(Node* next, Node* &head){
    //If the head is equal to the next (Start of the list)
    if(next == head){
        cout << "Students: " << endl;
    }
    //If the next node isn't equal to NULL
    if(next != NULL){
        //Print out the Student's info
        cout << next->getStudent()->getFirstName();
        cout << ", " << next->getStudent()-> getLastName();
        cout << ", " << next->getStudent()->getID();
        cout << ", " << setprecision(3) << next->getStudent()->getGPA() << endl;
    //Before you go off the end of the list
    if(next->getNext() != NULL){
    //Call print again
    print(next->getNext(), head);
    }
    }
}

//Deleting a student
void deleteStudent(Node* current, Node* &head, int id, Node* previous){
        //If the list is empty 
        if(head == NULL){
            cout << "You're trying to delete a student from an empty student list! Add a student before deleting any." << endl;
        }
        //If the current student's ID is equal to the ID entered
        if(current->getStudent()->getID() == id){
            //If the current node is the first one
            if(current == head){
                //Make the first node the second
                head = head->getNext();
                current->setNext(NULL);
                //Delete the node
                delete current;
                return;
            }
            else{
            //Skip the current node in the list
            previous->setNext(current->getNext()); 
            //Delete the node
            delete current;
            return;
            }
        }
        else {
            //Move to the next node
            delete(current->getNext(), head, id, current);
        }
}
//Averages the GPAs of all the students (Help from Jayden and Kyle)
void average(Node* head, float sum, int nodeCount){
    //If the node exists
    if(head != NULL){
    //Add the student's GPA to the total
    sum+=head->getStudent()->getGPA();
    //Add to the total node count
    nodeCount++;
    //Move to the next node in the list
    average(head->getNext(), sum, nodeCount);
    }
    //Otherwise, at the end of the list print out the GPA.
    else{
    cout << setprecision(3) << (float)(sum/nodeCount) << endl;
    }
}




