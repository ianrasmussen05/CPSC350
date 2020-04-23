// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Window.cpp

#include <iostream>

using namespace std;

#include "Student.h"
#include "Window.h"

Window::Window()
{
  idleTime = 0;
  currStudent = NULL; // the student must be NULL
}

Window::~Window()
{
  delete currStudent;
}
