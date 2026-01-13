/**
   Description: Linked Lists Part 2
   Author: Aahana Sapra
   Date: 1/9/2026
 */

#include <iostream>
#include <cstring>
#include <limits>
#include <ios>
#include "Node.h"
#include "Student.h"

// Define function prototypes
void addStudent(const int& INPUT_LENGTH);
void printStudentInfo();
void averageGPA();
void deleteStudent();
void quit();

using namespace std;

int main() {
  // Define const vars for commands
  const char ADD[] = "ADD";
  const char PRINT[] = "PRINT";
  const char AVERAGE[] = "AVERAGE";
  const char DELETE[] = "DELETE";
  const char QUIT[] = "QUIT";

  // Declare char arr for user input
  const int INPUT_LENGTH = 81;
  char userCommand[INPUT_LENGTH];

  // Continue prompting user for input until QUIT command
  bool keepModifying = true;
  while (keepModifying) {
    // read in user input
    cout << "Enter a command (ADD, PRINT, AVERAGE, DELETE, QUIT): ";
    cin.getline(userCommand, INPUT_LENGTH);
    
    // convert input to uppercase for comparison
    for (int i = 0; i < strlen(userCommand); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }

    // validate input
    if ((strcmp(userCommand, ADD) != 0) && (strcmp(userCommand, PRINT) != 0) &&
	(strcmp(userCommand, AVERAGE) != 0) && (strcmp(userCommand, DELETE) != 0) &&
	(strcmp(userCommand, QUIT) != 0)) {
      cout << "Please input ADD, PRINT, AVERAGE, DELETE, or QUIT." << endl;
    } else {
      // call appropriate method
      if (strcmp(userCommand, ADD) == 0) {
	addStudent(INPUT_LENGTH);
      } else if (strcmp(userCommand, PRINT) == 0) {
	printStudentInfo();
      } else if (strcmp(userCommand, AVERAGE) == 0) {
	averageGPA();
      } else if (strcmp(userCommand, DELETE) == 0) {
	deleteStudent();
      } else if (strcmp(userCommand, QUIT) == 0) {
	quit();
      }
    }
  }
  
  return 0;
}

// Create new student entry and sort linked list by student id
void addStudent(const int& INPUT_LENGTH) {
  // declare var for user input
  char firstName[INPUT_LENGTH];
  char lastName[INPUT_LENGTH];
  int id = 0;
  float gpa = 0.0;

  // read in user input
  cout << "Enter the student's first name: ";
  cin.getline(firstName, INPUT_LENGTH);

  cout << "Enter the student's last name: ";
  cin.getline(lastName, INPUT_LENGTH);

  cout << "Enter the student's ID: ";
  cin >> id;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

  cout << "Enter the student's GPA: ";
  cin >> gpa;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
}
