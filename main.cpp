/**
   Description: Linked Lists Part 2
   Author: Aahana Sapra
   Date: 1/9/2026
 */

#include <iostream>
#include <cstring>
#include <limits>
#include <ios>
#include <iomanip>
#include "Node.h"
#include "Student.h"

// Define function prototypes
void addStudent(Node*& head, const int& INPUT_LENGTH);
Node* sort(Node* head, Student* newStudent);
void printStudentInfo(Node* head);
void averageGPA(Node* head, float runningSum, int count);
void deleteStudent(Node*& head);
void quit(Node*& head);

using namespace std;

int main() {
  // Define linked list head Node
  Node* head = NULL;
  
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
	addStudent(head, INPUT_LENGTH);
      } else if (strcmp(userCommand, PRINT) == 0) {
	printStudentInfo(head);
      } else if (strcmp(userCommand, AVERAGE) == 0) {
	averageGPA(head, 0.0, 0);
      } else if (strcmp(userCommand, DELETE) == 0) {
	//deleteStudent(head);
      } else if (strcmp(userCommand, QUIT) == 0) {
	//quit(head);
      }
    }
  }
  
  return 0;
}

// Create new student entry and sort linked list by student ID
void addStudent(Node*& head, const int& INPUT_LENGTH) {
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

  // create new Student
  Student* newStudent = new Student(firstName, lastName, id, gpa);

  // insert new node and sort linked list
  head = sort(head, newStudent);
}

// Sort linked list by ID and insert new nodes accordingly
Node* sort(Node* head, Student* newStudent) {
  // base case: list is empty or at insertion point
  if ((head == NULL) ||
      (head->getStudent()->getID() > newStudent->getID())) {
    // create new Node
    Node* newNode = new Node(newStudent);
    newNode->setNext(head); // new node points to current node
    return newNode; // stop recursion: new node becomes new head of sublist
  }
  
  // recursive call: call function on next node in list
  head->setNext(sort(head->getNext(), newStudent));
  return head; // return current node
}

// Print entries in linked list
void printStudentInfo(Node* head) {
  // base case: reached end of list
  if (head == NULL) {
    return;
  }

  // recursive call
  cout << head->getStudent()->getFirstName() << ' '
       << head->getStudent()->getLastName() << ", "
       << head->getStudent()->getID() << ", "
       << fixed << setprecision(2) << head->getStudent()->getGPA() << endl;
  printStudentInfo(head->getNext());
}

// Calculate and output the average GPA of all students 
void averageGPA(Node* head, float runningSum, int count) {
  // base case: reached end of list
  if (head == NULL) {
    cout << "Average GPA: " << fixed << setprecision(2)
	 << (runningSum / count) << endl;
    return;
  }

  // recursive call
  runningSum += head->getStudent()->getGPA();
  count++;
  averageGPA(head->getNext(), runningSum, count);
}
