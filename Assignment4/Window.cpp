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
  currStudent = NULL;
}

Window::~Window()
{
  delete currStudent;
}
