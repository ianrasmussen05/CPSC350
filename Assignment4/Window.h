// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Window.h

#ifndef _WINDOW_H
#define _WINDOW_H

class Window
{
  private:
    // No private variables

  public:
  Window(); // Consturctor
  ~Window(); // Destructor

  int idleTime; // Integer representing the idle time of the window
  Student* currStudent; // Creates a student pointer 
};

#endif
