// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// DoughnutMode.h

#include "DoughnutMode.h"
#include "InputLife.h"

// Constructor
DoughnutMode::DoughnutMode()
{
  row = 0;
  column = 0;
  density = 0;
}

// Overloaded Constructor
DoughnutMode::DoughnutMode(int row, int column, double density)
{
  this->row = row;
  this->column = column;
  this->density = density;
}

// Destructor
DoughnutMode::~DoughnutMode()
{
  delete past;
  delete present;
  delete future;
}
