// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Student.cpp

#include <iostream>
#include <string>

using namespace std;

#include "Student.h"

Student::Student()
{
  timeNeeded = 0;
  timeArrived = 0;
  waitTime = 0;
  isInWindow = false;
}

Student::Student(int needed, int arrived, int wait)
{
  timeNeeded = needed;
  timeArrived = arrived;
  waitTime = wait;
  isInWindow = false;
}

Student::~Student()
{

}
