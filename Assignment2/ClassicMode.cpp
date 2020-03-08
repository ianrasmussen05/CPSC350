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
  delete generation;
  delete nextGeneration;
}

void ClassicMode::generateGrid()
{

}

void ClassicMode::countNeighbors()
{
  int counter = 0;

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      if (generation[i-1][j] == 'X' && i != 0) // Checks left neighbor
      {
        counter++;
      }
      if (generation[i+1][j] == 'X' && (i != column - 1)) // Checks the right neighbor
      {
        counter++;
      }
      if (generation[i][j-1] == 'X' && j != 0) // Checks the neighbor above
      {
        counter++;
      }
      if (generation[i][j+1] == 'X' && (j != row + 1)) // Checks the bottom neighbor
      {
        counter++;
      }

      // All the diagnal spots in the generation
      if (generation[i-1][j-1] == 'X' && (i != 0 && j != 0)) // Checks the top left neighbor
      {
        counter++;
      }
      if (generation[i+1][j-1] == 'X' && (i != column - 1 && j != 0)) // Checks the top right neighbor
      {
        counter++;
      }
      if (generation[i-1][j+1] == 'X' && (i != 0 && j != row - 1)) // Checks the bottom left neighbor
      {
        counter++;
      }
      if (generation[i+1][j+1] == 'X' && (i != column - 1 && j != row - 1)) // Checks the bottom right neighbor
      {
        counter++;
      }

      // implement the future values for next generation
      if (counter <= 1 || counter >= 4)
      {
        nextGeneration[i][j] = '-';
      }
      else if (counter == 2)
      {
        nextGeneration[i][j] = generation[i][j];
      }
      else if (counter == 3)
      {
        nextGeneration[i][j] = 'X';
      }

      counter = 0;
    }
  }
}
