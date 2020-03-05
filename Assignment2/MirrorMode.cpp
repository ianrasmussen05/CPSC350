// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// MirrorMode.cpp

#include "MirrorMode.h"

// Constructor
MirrorMode::MirrorMode()
{
  row = 0;
  column = 0;
  density = 0;
}

// Overloaded Constructor
MirrorMode::MirrorMode(int row, int column, double density)
{
  this->row = row;
  this->column = column;
  this->density = density;
}

// Destructor
MirrorMode::~MirrorMode()
{

}
