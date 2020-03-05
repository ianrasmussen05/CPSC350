// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// ClassicMode.cpp

#include "ClassicMode.h"
#include "InputLife.h"

// Constructor
ClassicMode::ClassicMode()
{
  row = 0;
  column = 0;
  density = 0;
}

// Overloaded Constructor
ClassicMode::ClassicMode(int row, int column, double density)
{
  this->row = row;
  this->column = column;
  this->density = density;
}

// Destructor
ClassicMode::~ClassicMode()
{
  delete past;
  delete present;
  delete future;
}
