// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// InputLife.cpp

#include "InputLife.h"

 // Constructor
InputLife::InputLife()
{
  row = 0;
  column = 0;
  density = 0.0;
  fileName = "\0";
}

// Destructor
InputLife::~InputLife()
{

}

string InputLife::FileOrConsole()
{
  


  return "\0";
}

void InputLife::ReadFile()
{

}




// Getters for all variables
int InputLife::getRow()
{
  return row;
}

int InputLife::getColumn()
{
  return column;
}

double InputLife::getDensity()
{
  return density;
}

string InputLife::getFileName()
{
  return fileName;
}


// Setters for all variables
void InputLife::setRow(int row)
{
  this->row = row;
}

void InputLife::setColumn(int column)
{
  this->column = column;
}

void InputLife::setDensity(double density)
{
  this->density = density;
}

void InputLife::setFileName(string fileName)
{
  this->fileName = fileName;
}
