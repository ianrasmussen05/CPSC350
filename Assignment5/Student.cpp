// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Student.cpp

#include <iostream>
#include <string>

using namespace std;

#include "Student.h"


// Default constructor
Student::Student()
{
  id = 0;
  name = "\0";
  level = "\0";
  major = "\0";
  gpa = 0.0;
  advisor = 0;
}

// Overloaded constructor
Student::Student(int id, string name, string level, string major, double gpa, int advisor)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->major = major;
  this->gpa = gpa;
  this->advisor = advisor;
}

// Destructor
Student::~Student()
{

}


// Getters
int Student::getID()
{
  return id;
}

string Student::getName()
{
  return name;
}

string Student::getLevel()
{
  return level;
}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return gpa;
}

int Student::getAdvisor()
{
  return advisor;
}


// Setters
void Student::setID(int id)
{
  this->id = id;
}

void Student::setName(string name)
{
  this->name = name;
}

void Student::setLevel(string level)
{
  this->level = level;
}

void Student::setMajor(string major)
{
  this->major = major;
}

void Student::setGPA(double gpa)
{
  this->gpa = gpa;
}

void Student::setAdvisor(int advisor)
{
  this->advisor = advisor;
}
