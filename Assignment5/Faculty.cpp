#include <iostream>
#include <string>

using namespace std;

#include "Faculty.h"

Faculty::Faculty()
{
  id = 0;
  name = "\0";
  level = "\0";
  department = "\0";
  numOfStudents = 0;
}

Faculty::Faculty(int id, string name, string level, string department, int numOfStudents)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
  this->numOfStudents = numOfStudents;
}

Faculty::~Faculty()
{

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

int Faculty::getNumOfStudents()
{
  return numOfStudents;
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

void Faculty::setNumOfStudents(int numOfStudents)
{
  this->numOfStudents = numOfStudents;
}
