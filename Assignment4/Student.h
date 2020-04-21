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
    Student();
    Student(int needed, int arrived);
    ~Student();

    int timeNeeded;
    int timeArrived;
};

#endif
