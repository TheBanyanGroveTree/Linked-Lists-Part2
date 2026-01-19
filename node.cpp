#include <iostream>
using namespace std;
#include "node.h"

//constructor
Node::Node(Student* newStudent) {
  student = newStudent;
  next = nullptr;
}
//destructor
Node::~Node() {
  next = nullptr;
}
//get next nodes for printing
Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
//get the student included in node
Student* Node::getStudent() {
  return student;
}

