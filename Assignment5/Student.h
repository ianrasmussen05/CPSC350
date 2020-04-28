// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Student.h

#ifndef _STUDENT_H
#define _STUDENT_H

class Student
{
  private:
    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;

  public:
    Student();
    Student(int id, string name, string level, string major, double gpa, int advisor);
    ~Student();

    // Getters
    int getID();
    string getName();
    string getLevel();
    string getMajor();
    double getGPA();
    int getAdvisor();

    // Setters
    void setID(int id);
    void setName(string name);
    void setLevel(string level);
    void setMajor(string major);
    void setGPA(double gpa);
    void setAdvisor(int advisor);
};

#endif
