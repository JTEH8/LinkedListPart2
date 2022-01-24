//Node functions
#include <iostream>
#include <cstring>

#include "Node.h"

using namespace std;

Node::Node(Student* inStudent) { //constructor
  student = inStudent;
  next = NULL;
}

Student* Node::getStudent() { //getter for student
  return student;
}

Node* Node::getNext() { //getter for next node
  return next;
}

void Node::setNext(Node* inNext) { //setter for next node
  next = inNext;
}

Node::~Node() { //destructor
  delete student;
  next = NULL;
}