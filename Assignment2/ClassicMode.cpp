// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// ClassicMode.cpp

#include "ClassicMode.h"

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

}
