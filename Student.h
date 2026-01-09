#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  Student(); // Default constructor
  Student(char*, char*, int, float); // Constructor with parameters
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  ~Student(); // Destructor
 private:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};

#endif
