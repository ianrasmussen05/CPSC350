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
  row = 5;
  column = 5;

  generation = new char *[column];
  nextGeneration = new char *[column];

  for (int i = 0; i < column; ++i)
  {
    generation[i] = new char[row];
    nextGeneration[i] = new char[row];
  }

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      generation[i][j] = '-';
      nextGeneration[i][j] = '-';
    }
  }
}

// Overloaded Constructor
ClassicMode::ClassicMode(int row, int column)
{
  this->row = row;
  this->column = column;

  generation = new char *[column];
  nextGeneration = new char *[column];

  for (int i = 0; i < column; ++i)
  {
    generation[i] = new char[row];
    nextGeneration[i] = new char[row];
  }

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      generation[i][j] = '-';
      nextGeneration[i][j] = '-';
    }
  }


}

// Destructor
ClassicMode::~ClassicMode()
{
  delete generation;
  delete nextGeneration;
}

void ClassicMode::generateGrid()
{
  double totalCells = 0;
  double densityOfGrid = 0;
  int numDensity = 0;

  InputLife *inputGrid = new InputLife();

  inputGrid->getRow();
  inputGrid->getColumn();

  totalCells = (double)column * row;
  densityOfGrid = density * totalCells;

  // Figure out how to get the remainder of the decimal
  if ((densityOfGrid / 100) >= 0.5)
  {

  }

  while (numDensity != 0)
  {
    for (int i = 0; i < column; ++i)
    {
      for (int j = 0; j < row; ++j)
      {
        if (numDensity == 0)
        {
          break;
        }

        double randNum = rand() % 100;

        if (randNum <= density)
        {
          generation[i][j] = 'X';
          numDensity--;
        }
      }
    }
  }

  delete inputGrid;
}

void ClassicMode::countNeighbors()
{
  int counter = 0;

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      counter = 0; // Resets the counter each iteration

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
    }
  }
}

bool ClassicMode::isEmpty()
{
  InputLife *inputGrid = new InputLife();

  inputGrid->getRow();
  inputGrid->getColumn();

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      if (nextGeneration[i][j] == 'X')
      {
        delete inputGrid;
        return false;
      }
    }
  }

  delete inputGrid;
  return true;
}
