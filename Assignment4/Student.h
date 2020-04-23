// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Student.h

#ifndef _STUDENT_H
#define _STUDENT_H

class Student
{
  private:
    // No private variables

  public:
    Student(); // Consturctor
    Student(int needed, int arrived, int wait); // Overloaded constructor
    ~Student(); // Destructor

    int timeNeeded; // Integer for the time needed for the student
    int timeArrived; // Integer for the time the student arrived at
    int waitTime; // Integer for the wait time of the student
    bool isInWindow; // Boolean checking if the student is in a window
};

#endif
