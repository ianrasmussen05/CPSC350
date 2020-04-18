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
