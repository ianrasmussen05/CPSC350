// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Faculty.h

#ifndef _FACULTY_H
#define _FACULTY_H

class Faculty
{
  private:
    int id;
    string name;
    string level;
    string department;
    LinkedList<int> *listOfStudents; // List of advisees

  public:
    Faculty(); // Default constructor
    Faculty(int id, string name, string level, string department, LinkedList<int> *listOfStudents); // Overloaded constructor
    ~Faculty(); // Destructor

    // Getters
    int getID();
    string getName();
    string getLevel();
    string getDepartment();
    LinkedList<int> *getListOfStudents();

    // Setters
    void setID(int id);
    void setName(string name);
    void setLevel(string level);
    void setDepartment(string department);
};

#endif
