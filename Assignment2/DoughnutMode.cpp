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
DoughnutMode::DoughnutMode(int row, int column)
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

DoughnutMode::DoughnutMode(int row, int column, double density)
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
DoughnutMode::~DoughnutMode()
{
  delete generation;
  delete nextGeneration;
}

void DoughnutMode::generateGridRandom()
{
  double totalCells = 0;
  double densityOfGrid = 0;
  int densityCount = 0;

  InputLife *inputGrid = new InputLife();

  inputGrid->getRow();
  inputGrid->getColumn();
  inputGrid->getDensity();

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

void DoughnutMode::countNeighbors(char **grid, int row, int column)
{
  int counter = 0;

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      counter = 0; // Resets the counter each iteration

      char topLeftCorner = grid[0][0];
      char topRightCorner = grid[column-1][0];
      char bottomLeftCorner = grid[0][row-1];
      char bottomRightCorner = grid[column-1][row-1];

      // Checks the top left corner of the grid, and checks the wrapped grid
      if (grid[i][j] == grid[0][0])
      {
        if (grid[0][1] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (grid[1][0] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (grid[1][1] == 'X') // Chekcs the bottom right neighbor
        {
          counter++;
        }

        if (grid[column-1][row-1] == 'X') // Checks the opposite corner of the grid
        {
          counter++;
        }

        if (grid[column-1][0] == 'X') // Checks the horizontal opposite side of grid
        {
          counter++;
        }
        if (grid[column-1][1] == 'X') // Checks diagnal horizontal opposite side of grid
        {
          counter++;
        }
        if (grid[0][row-1] == 'X') // Checks vertical opposite side of grid
        {
          counter++;
        }
        if (grid[1][row-1] == 'X') // Checks diagnal vertical opposite side of grid
        {
          counter++;
        }
      }

      // Checks to see if the spot is in the top right corner
      if (grid[i][j] == grid[column-1][0])
      {
        if (grid[column-2][0] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (grid[column-1][1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }
        if (grid[column-2][1] == 'X') // Checks the bottom left neighbor
        {
          counter++;
        }

        if (grid[0][row-1] == 'X') // Checks opposite corner neighbor of grid
        {
          counter++;
        }

        if (grid[0][0] == 'X') // Checks opposite horizontal side of grid
        {
          counter++;
        }
        if (grid[0][1] == 'X') // Checks diagnal horizontal opposite side of grid
        {
          counter++;
        }
        if (grid[column-1][row-1] == 'X') // Checks the vertical opposite side of grid
        {
          counter++;
        }
        if (grid[column-2][row-1] == 'X') // Checks the diagnal vertical opposite of grid
        {
          counter++;
        }
      }

      // Checks to see if the spot is in the bottom left corner
      if (grid[i][j] == grid[0][row-1])
      {
        if (grid[1][row-1] == 'X') // Checks the right of the corner
        {
          counter++;
        }
        if (grid[0][row-2] = 'X') // Checks the top neighbor of the corner
        {
          counter++;
        }
        if (grid[1][row-2] == 'X') // Checks the top right neighbor of the corner
        {
          counter++;
        }

          if (grid[column-1][0] == 'X') // Checks the top right of grid, opposite corner
        {
          counter++;
        }
          if (grid[0][0] == 'X') // The vertical opposite of bottom left corner
        {
          counter++;
        }
        if (grid[1][0] == 'X') // Checks the diagnal veritcal opposite side of bottome left corner
        {
          counter++;
        }
        if (grid[column-1][row-1] == 'X') // Checks bottom right corner of grid
        {
          counter++;
        }
        if (grid[column-1][row-2] == 'X') // Checks diagnal neighbor from horizontal opposite side
        {
          counter++;
        }
      }
        // Checks to see if the value is at the bottom right corner
      if (grid[i][j] == grid[column-1][row-1])
      {
        if (grid[column-2][row-1] == 'X') // Checks the left neighbor of the bottom right corner
        {
          counter++;
        }
        if (grid[column-1][row-2] == 'X') // Checks the top neighbor of the bottom right corner
        {
          counter++;
        }
        if (grid[column-2][row-2] == 'X') // Checks the top left neighbor of bottom right corner
        {
          counter++;
        }

        if (grid[0][0] == 'X') // Checks the top left of the grid
        {
          counter++;
        }

        if (grid[column-1][0] == 'X') // Checks the top right corner of grid
        {
          counter++;
        }
        if (grid[column-2][0] == 'X') // Checks the left of the top right corner of the grid
        {
          counter++;
        }
        if (grid[0][row-1] == 'X') // Checks the bottom left of the grid
        {
          counter++;
        }
        if (grid[0][row-2] == 'X') // Checks the top of the bottom left of the grid
        {
          counter++;
        }
      }

      char leftBorder = grid[0][j];
      char topBorder = grid[i][0];
      char rightBorder = grid[column-1][j];
      char bottomBorder = grid[i][row-1];

      // Checks the left border of the grid
      if ((grid[i][j] == leftBorder) && (leftBorder != (topLeftCorner || bottomLeftCorner)))
      {
        if (grid[1][j] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (grid[i][j-1] == 'X') // Checks the top neighbor
        {
          counter++;
        }
        if (grid[i][j+1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }
        if (grid[1][j-1] == 'X') // Checks the top left neighbor
        {
          counter++;
        }
        if (grid[1][j+1] == 'X') // Checks the bottom right neighbor
        {
          counter++;
        }

        if (grid[column-1][j] == 'X') // Checks opposite (right side) neighbor
        {
          counter++;
        }
        if (grid[column-1][j-1] == 'X') // Checks opposite side top neighbor
        {
          counter++;
        }
        if (grid[column-1][j+1] == 'X') // Checks opposite side bottom neighbor
        {
          counter++;
        }
      }

      // Checks the top border of the grid
      if ((grid[i][j] == topBorder) && (topBorder != (topLeftCorner || topRightCorner)))
      {
        if (grid[i+1][j] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (grid[i-1][j] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (grid[i][j+1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }
        if (grid[i-1][j+1] == 'X') // Checks the bottom left neighbor
        {
          counter++;
        }
        if (grid[i+1][j+1] == 'X') // Checks the bottom right neighbor
        {
          counter++;
        }

        if (grid[i][row-1] == 'X') // Checks the opposite side neighbor
        {
          counter++;
        }
        if (grid[i-1][row-1] == 'X') // Checks left opposite side neighbor
        {
          counter++;
        }
        if (grid[i+1][row-1] == 'X') // Checks right opposite side neighbor
        {
          counter++;
        }
      }
      // Checks the right border of the grid
      if ((grid[i][j] == rightBorder) && (rightBorder != (topRightCorner || bottomRightCorner)))
      {
        if (grid[column-2][j] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (grid[column-1][j-1] == 'X') // Checks the top neighbor
        {
          counter++;
        }
        if (grid[column-1][j+1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }
        if (grid[column-2][j-1] == 'X') // Checks top left neighbor
        {
          counter++;
        }
        if (grid[column-2][j+1] == 'X') // Checks the bottom left neighbor
        {
          counter++;
        }

        if (grid[0][j] == 'X') // Checks the left side spot
        {
          counter++;
        }
        if (grid[0][j-1] == 'X') // Checks the top spot on left side of grid
        {
          counter++;
        }
        if (grid[0][j+1] == 'X') // Checks the bottom spot on left side of grid
        {
          counter++;
        }
      }
      // Checks the bottom border of the grid
      if ((grid[i][j] == bottomBorder) && (bottomBorder != (bottomLeftCorner || bottomRightCorner)))
      {
        if (grid[i-1][j] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (grid[i+1][j] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (grid[i][j-1] == 'X') // Checks the top neighbor
        {
          counter++;
        }
        if (grid[i-1][j-1] == 'X') // Checks the top left neighbor
        {
          counter++;
        }
        if (grid[i+1][j-1] == 'X') // Checks the top right neighbor
        {
          counter++;
        }

        if (grid[i][0] == 'X') // Checks the top of grid
        {
          counter++;
        }
        if (grid[i-1][0] == 'X') // Checks the left of the top of grid
        {
          counter++;
        }
        if (grid[i+1][0] == 'X') // Checks the right of the top of grid
        {
          counter++;
        }
      }

      // If the center of the grid is called on
      if (grid[i][j] != (bottomLeftCorner || bottomRightCorner || topLeftCorner || topRightCorner || bottomBorder || leftBorder || topBorder || rightBorder))
      {
        if (grid[i-1][j-1] == 'X') // Checks the top left spot
        {
          counter++;
        }
        if (grid[i][j-1] == 'X') // Checks the top spot
        {
          counter++;
        }
        if (grid[i+1][j-1] == 'X') // Checks the top right spot
        {
          counter++;
        }
        if (grid[i-1][j] == 'X') // Checks the left spot
        {
          counter++;
        }
        if (grid[i+1][j] == 'X') // Checks the right spot
        {
          counter++;
        }
        if (grid[i-1][j+1] == 'X') // Checks the bottom left spot
        {
          counter++;
        }
        if (grid[i][j+1] == 'X') // Checks the bottom spot
        {
          counter++;
        }
        if (grid[i+1][j+1] == 'X') // Checks the bottom right spot
        {
          counter++;
        }
      }


      // This is what should be implemented with counter
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

bool DoughnutMode::isEmpty(char **grid, int row, int column)
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

void DoughnutMode::printGrid(char **grid, int row, int column)
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

void DoughnutMode::setGeneration(char **grid)
{
  generation = grid;
}

void DoughnutMode::setNextGeneration(char **grid)
{
  nextGeneration = grid;
}

char** DoughnutMode::getGeneration()
{
  return generation;
}

char** DoughnutMode::getNextGeneration()
{
  return nextGeneration;
}
