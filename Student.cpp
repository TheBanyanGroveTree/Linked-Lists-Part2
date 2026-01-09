#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student() {
  firstName = new char[81];
  lastName = new char[81];
  id = 0;
  gpa = 0.0;
}

Student::Student(char* firstName, char* lastName, int id, float gpa) {
  this->firstName = new char[81];
  strcpy(this->firstName, firstName);

  this->lastName = new char[81];
  strcpy(this->lastName, lastName);

  this->id = id;
  this->gpa = gpa;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}

Student::~Student() {
  delete firstName, lastName;
}
