#ifndef NODE_H
#define NODE_H
using namespace std;
class Student; //use for your student class(you can modify this line)
class Node {
 public:
  //constructor, destructors, etc.
  Node(Student* newStudent);
  ~Node();
  Node* getNext();
  void setNext(Node* newNext);
  Student* getStudent();
 private:
  //variables
  Student* student;
  Node* next;
};
#endif

