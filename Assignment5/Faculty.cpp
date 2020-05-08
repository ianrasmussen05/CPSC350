// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Faculty.cpp

#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"


// Default constructor
Faculty::Faculty()
{
  id = 0;
  name = "\0";
  level = "\0";
  department = "\0";
  listOfStudents = new LinkedList<int>();
}

// Overloaded Construcor
Faculty::Faculty(int id, string name, string level, string department, LinkedList<int> *listOfStudents)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
  this->listOfStudents = listOfStudents;
}

// Destructor
Faculty::~Faculty()
{
  delete listOfStudents;
}


// Getters
int Faculty::getID()
{
  return id;
}

string Faculty::getName()
{
  return name;
}

string Faculty::getLevel()
{
  return level;
}

string Faculty::getDepartment()
{
  return department;
}

LinkedList<int> *Faculty::getListOfStudents()
{
  return listOfStudents;
}


// Setters
void Faculty::setID(int id)
{
  this->id = id;
}

void Faculty::setName(string name)
{
  this->name = name;
}

void Faculty::setLevel(string level)
{
  this->level = level;
}

void Faculty::setDepartment(string department)
{
  this->department = department;
}
