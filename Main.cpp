#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;
void add(Node* head, Student* newStudent);
void print(Node* next, Node* head);
void deleteStudent(Node* next, Node* head, int id, Node* previous);
void average(Node* head, float &sum, int &nodeCount);

int main(){
Node* head = NULL;
bool playing = true;
while(playing == true){
cout <<"Welcome to Student List (Linked Lists edition)! Enter a student into a list by adding their first and lastnames, student ID, and GPA." << endl;
cout << "TO add a student, type 'ADD'. To delte a student, type 'DELETE'. To print the list, type 'PRINT'. To print the average GPA of all students, type 'AVERAGE'. To quit, type 'QUIT'." << endl;
char input[10];
cin >> input;
if(strcmp(input, "ADD") == 0){
    Student* s = new Student();
    cout << "You're adding a new student!" << endl;
    cout << "Enter their name." << endl;
    cin >> s->firstName;
    cout << "Enter their lastname." << endl;
    cin >> s->lastName;
    cout << "Enter their student ID." << endl;
    cin >> s->ID;
    cout << "Enter their GPA." << endl;
    cin >> s->GPA;
    add(head, s);
}
if(strcmp(input, "DELETE") == 0){
    int input = 0;
    cout << "Enter the student ID of the student you're deleting" << endl;
    cin >> input;
    deleteStudent(head, head, input, NULL);
}
if(strcmp(input, "PRINT") == 0){
    print(head, head);
    cout << endl;
}
if(strcmp(input, "AVERAGE") == 0){
    float sum = 0;
    int nodeCount = 0;
    average(head, sum, nodeCount);
    cout << setprecision(2) << (float)(sum/nodeCount) << endl;
}
if(strcmp(input, "QUIT") == 0){
 playing = false;
}

}

}

void add(Node* head, Student* newStudent){
    if(head == NULL){
        head = new Node(newStudent);
        return;
    }
    if(head->getNext() == NULL){
    Node* temp = new Node(newStudent);
    if(head->getStudent()->getID() > newStudent->ID){
        temp->setNext(head);
        head=temp;
    }
    else{
    head->setNext(temp);    
    }
    return;
    }

    if(head->getStudent()->getID() > newStudent->ID){
        Node* temp2 = new Node(newStudent);
        temp2->setNext(head);
        temp2->setNext(head->getNext());
        head->setNext(temp2);
        return;
        }
    Node* called = head->getNext();
    add(called, newStudent);    
    }
void print(Node* next, Node* head){
    if(next == head){
        cout << "Students: " << endl;
    }
    if(next != NULL){
        cout << next->getStudent()->firstName;
        cout << " " << next->getStudent()-> lastName;
        cout << " " << next->getStudent()->getID();
        cout << " " << setprecision(2) << next->getStudent()->getGPA() << endl;
    print(next->getNext(), head);
}
}

void deleteStudent(Node* next, Node* head, int id, Node* previous){
        if(next->getStudent()->getID() == id){
            if(previous == NULL){
                head = next->getNext();
            }
            else{
            previous->setNext(next->getNext()); 
            }
            delete next;
            return;
        }
        else if(next->getNext() != NULL){
            delete(next->getNext(), head, id, next);
        }
}
void average(Node* head, float &sum, int &nodeCount){
    if(head!= NULL){
    sum+=head->getStudent()->getGPA();
    nodeCount++;
    if(head->getNext() != NULL){
        average(head, sum, nodeCount);
    }
    }
}




