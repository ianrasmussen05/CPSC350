// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// MirrorMode.cpp

#include "MirrorMode.h"
#include "InputLife.h"

// Default Constructor
MirrorMode::MirrorMode()
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
MirrorMode::MirrorMode(int row, int column)
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

// Overloaded constructor
MirrorMode::MirrorMode(int row, int column, double density)
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
MirrorMode::~MirrorMode()
{
  delete generation;
  delete nextGeneration;
}

void MirrorMode::generateGridRandom()
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

// When the user inputs a file, call this
void MirrorMode::generateGridFile()
{

}

// Counts the neighbors of each part in the inputed grid
void MirrorMode::countNeighbors(char **grid, int row, int column)
{
  int counter = 0;

  // Originally I wanted to do row then column, but I messed up too far and I switched the values
  // in the nested for loop
  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      counter = 0; // Resets the counter each iteration

      char topLeftCorner = grid[0][0];
      char topRightCorner = grid[column-1][0];
      char bottomLeftCorner = grid[0][row-1];
      char bottomRightCorner = grid[column-1][row-1];

      // The next if statements check to see if its a corner
      // Checks to see if it is at the top left corner
      if (grid[i][j] == topLeftCorner)
      {
        if (topLeftCorner == 'X')
        {
          counter += 3;
        }
        if (grid[1][0] == 'X') // Checks the right spot from the left corner
        {
          counter++;
        }
        if (grid[0][1] == 'X') // Checks the bottom spot from the left corner
        {
          counter++;
        }
      }
      // Checks to see if it is at the top right corner
      else if (grid[i][j] == topRightCorner)
      {
        if (topRightCorner == 'X')
        {
          counter += 3;
        }
        if (grid[column-2][0] == 'X') // Checks the left of the right corner
        {
          counter++;
        }
        if (grid[column-1][1] == 'X') // Chekcs the bottom of the right corner
        {
          counter++;
        }
      }
      // Checks to see if it is at the bottom left corner
      else if (grid[i][j] == bottomLeftCorner)
      {
        if (bottomLeftCorner == 'X')
        {
          counter += 3;
        }
        if (grid[1][row-1] == 'X') // Checks the right spot from the bottom left corner
        {
          counter++;
        }
        if (grid[0][row-2] == 'X') // Checks the top spot
        {
          counter++;
        }
      }
      // Checks to see if it is at the bottom right corner
      else if (grid[i][j] == bottomRightCorner)
      {
        if (bottomRightCorner == 'X')
        {
          counter += 3;
        }
        if (grid[column-1][row-2] == 'X') // Checks the top of the spot
        {
          counter++;
        }
        if (grid[column-2][row-1] == 'X') // Checks the left of the spot
        {
          counter++;
        }
      }

      // Checking the left border of the grid
      if (i == 0 && (j != 0 || j != row-1))
      {
        if (grid[i][j] == 'X') // Checks to see if value is X to add from the mirror rules
        {
          counter++;
        }
        if (grid[i][j-1] == 'X') // Checks the top spot
        {
          counter++;
        }
        if (grid[i][j+1] == 'X') // Checks the bottom spot
        {
          counter++;
        }
      }
      else if (j == 0 && (i != 0 && i != column-1))  // Checking the top border of the grid
      {
        if (grid[i][0] == 'X') // Checks to see if spot has X and adds to counter because of mirror
        {
          counter++;
        }
        if (grid[i-1][0] == 'X') // Checks the left spot
        {
          counter++;
        }
        if (grid[i+1][0] == 'X') // Checks the right spot
        {
          counter++;
        }
      }
      else if (i == column-1 && (j != row-1 && j != 0))   // Checking the right border of the grid
      {
        if (grid[i][j] == 'X') // Checks to see if spot has X and adds to counter because of mirror mode
        {
          counter++;
        }
        if (grid[column-1][j-1] == 'X') // Checks the top spot
        {
          counter++;
        }
        if (grid[column-1][j+1] == 'X') // Checks the bottom spot
        {
          counter++;
        }
      }
      else if (j == row-1 && (i != 0 && i != column-1)) // Checking the bottom border of the grid
      {
        if (grid[i][j] == 'X') // Checks to see if spot has X and adds to counter because of mirror mode
        {
          counter++;
        }
        if (grid[i-1][row-1] == 'X') // Checks the left spot
        {
          counter++;
        }
        if (grid[i+1][row-1] == 'X') // Checks the right spot
        {
          counter++;
        }
      }

      // Checks the normal neighbors
      if (i != 0 && grid[i-1][j] == 'X') // Checks the left neighbor
      {
        counter++;
      }
      if (i != column-1 && grid[i+1][j] == 'X') // Checks the right neighbor
      {
        counter++;
      }
      if (j != 0 && grid[i][j-1] == 'X') // Checks the top neighbor
      {
        counter++;
      }
      if (j != row-1 && grid[i][j+1] == 'X') // Checks the bottom neighbor
      {
        counter++;
      }

      // Checks the diagnal neighbors
      if ((i != 0 && j != 0) && grid[i-1][j-1] == 'X') // Checks the top left neighbor
      {
        counter++;
      }
      if ((i != column-1 && j != 0) && grid[i+1][j-1] == 'X') // Checks the top right neighbor
      {
        counter++;
      }
      if ((i != 0 && j != row-1) && grid[i-1][j+1] == 'X') // Checks the bottom left neighbor
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

// Checks if the grid is empty
bool MirrorMode::isEmpty(char **grid, int row, int column)
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

// Prints the entire grid when called
void MirrorMode::printGrid(char **grid, int row, int column)
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
void MirrorMode::setGeneration(char **grid)
{
  generation = grid;
}

void MirrorMode::setNextGeneration(char **grid)
{
  nextGeneration = grid;
}

// Getters
char** MirrorMode::getGeneration()
{
  return generation;
}

char** MirrorMode::getNextGeneration()
{
  return nextGeneration;
}
