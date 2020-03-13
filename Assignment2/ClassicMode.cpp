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

// Overloaded Constructor
ClassicMode::ClassicMode(int row, int column, double density)
{
  this->row = row;
  this->column = column;
  this->density = density;

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

// Generates a grid from the random input
void ClassicMode::generateGridRandom()
{
  double totalCells = 0;
  double densityOfGrid = 0;
  int densityCount = 0;

  InputLife *inputGrid = new InputLife();

  inputGrid->getRow();
  inputGrid->getColumn();
  inputGrid->getDensity();
  inputGrid->getFileName();

  totalCells = column * row;
  densityOfGrid = density * (double)totalCells;

  densityCount = (int)densityOfGrid;

  while (densityCount != 0)
  {
    for (int i = 0; i < column; ++i)
    {
      for (int j = 0; j < row; ++j)
      {
        if (densityCount == 0)
        {
          break;
        }

        double randNum = rand() % 100;

        if (randNum <= density * 100)
        {
          generation[i][j] = 'X';
          densityCount--;
        }
      }
    }
  }

  printGrid(generation, row, column);


  if (isEmpty(generation, row, column))
  {
    cout << "The file is empty." << endl;
    exit(0);
  }

  countNeighbors(generation, row, column);

  delete inputGrid;
}

// Used to get the user input for a file, not finished
void ClassicMode::generateGridFile()
{

}

// Counts each spot in the inputed grid and determines which cell dies or lives
void ClassicMode::countNeighbors(char **grid, int row, int column)
{
  int counter = 0;

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      counter = 0; // Resets the counter each iteration


      // I was receiving a segmentation fault when trying to check the neighbors in classic mode, but I figured
      // it out by switching the two conditions in each if statement
      if (i != 0 && grid[i-1][j] == 'X') // Checks left neighbor
      {
        counter++;
      }
      if ((i != column-1) && grid[i+1][j] == 'X') // Checks the right neighbor
      {
        counter++;
      }
      if (j != 0 && grid[i][j-1] == 'X') // Checks the neighbor above
      {
        counter++;
      }
      if ((j != row+1) && grid[i][j+1] == 'X') // Checks the bottom neighbor
      {
        counter++;
      }

      // All the diagnal spots in the generation
      if ((i != 0 && j != 0) && grid[i-1][j-1] == 'X') // Checks the top left neighbor
      {
        counter++;
      }
      if ((i != column-1 && j != 0) && grid[i+1][j-1] == 'X') // Checks the top right neighbor
      {
        counter++;
      }
      if ((i != 0 && j != row-1) && (grid[i-1][j+1] == 'X')) // Checks the bottom left neighbor
      {
        counter++;
      }
      if ((i != column-1 && j != row-1) && grid[i+1][j+1] == 'X') // Checks the bottom right neighbor
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
        nextGeneration[i][j] = grid[i][j];
      }
      else if (counter == 3)
      {
        nextGeneration[i][j] = 'X';
      }
    }
  }
}

bool ClassicMode::isEmpty(char **grid, int row, int column)
{
  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      if (grid[i][j] == 'X')
      {
        return false;
      }
    }
  }

  return true;
}

// Prints the entire grid with inputed grid
void ClassicMode::printGrid(char **grid, int row, int column)
{
  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

// Setters
void ClassicMode::setGeneration(char **grid)
{
  generation = grid;
}

void ClassicMode::setNextGeneration(char **grid)
{
  nextGeneration = grid;
}

// Getters
char** ClassicMode::getGeneration()
{
  return generation;
}

char** ClassicMode::getNextGeneration()
{
  return nextGeneration;
}
