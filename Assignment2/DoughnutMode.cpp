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
  delete generation;
}

void DoughnutMode::generateGrid()
{

}

void DoughnutMode::countNeighbors()
{
  int counter = 0;

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      char topLeftCorner = generation[0][0];
      char topRightCorner = generation[column-1][0];
      char bottomLeftCorner = generation[0][row-1];
      char bottomRightCorner = generation[column-1][row-1];

      // Checks the top left corner of the grid, and checks the wrapped grid
      if (generation[i][j] == generation[0][0])
      {
        if (generation[0][1] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (generation[1][0] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (generation[1][1] == 'X') // Chekcs the bottom right neighbor
        {
          counter++;
        }

        if (generation[column-1][row-1] == 'X') // Checks the opposite corner of the grid
        {
          counter++;
        }

        if (generation[column-1][0] == 'X') // Checks the horizontal opposite side of grid
        {
          counter++;
        }
        if (generation[column-1][1] == 'X') // Checks diagnal horizontal opposite side of grid
        {
          counter++;
        }
        if (generation[0][row-1] == 'X') // Checks vertical opposite side of grid
        {
          counter++;
        }
        if (generation[1][row-1] == 'X') // Checks diagnal vertical opposite side of grid
        {
          counter++;
        }
      }

      // Checks to see if the spot is in the top right corner
      if (generation[i][j] == generation[column-1][0])
      {
        if (generation[column-2][0] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (generation[column-1][1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }
        if (generation[column-2][1] == 'X') // Checks the bottom left neighbor
        {
          counter++;
        }

        if (generation[0][row-1] == 'X') // Checks opposite corner neighbor of grid
        {
          counter++;
        }

        if (generation[0][0] == 'X') // Checks opposite horizontal side of grid
        {
          counter++;
        }
        if (generation[0][1] == 'X') // Checks diagnal horizontal opposite side of grid
        {
          counter++;
        }
        if (generation[column-1][row-1] == 'X') // Checks the vertical opposite side of grid
        {
          counter++;
        }
        if (generation[column-2][row-1] == 'X') // Checks the diagnal vertical opposite of grid
        {
          counter++;
        }

        // Checks to see if the spot is in the bottom left corner
        if (generation[i][j] == generation[0][row-1])
        {
          if (generation[1][row-1] == 'X') // Checks the right of the corner
          {
            counter++;
          }
          if (generation[0][row-2] = 'X') // Checks the top neighbor of the corner
          {
            counter++;
          }
          if (generation[1][row-2] == 'X') // Checks the top right neighbor of the corner
          {
            counter++;
          }

          if (generation[column-1][0] == 'X') // Checks the top right of grid, opposite corner
          {
            counter++;
          }

          if (generation[0][0] == 'X') // The vertical opposite of bottom left corner
          {
            counter++;
          }
          if (generation[1][0] == 'X') // Checks the diagnal veritcal opposite side of bottome left corner
          {
            counter++;
          }
          if (generation[column-1][row-1] == 'X') // Checks bottom right corner of grid
          {
            counter++;
          }
          if (generation[column-1][row-2] == 'X') // Checks diagnal neighbor from horizontal opposite side
          {
            counter++;
          }
        }

        // Checks to see if the value is at the bottom right corner
        if (generation[i][j] == generation[column-1][row-1])
        {
          if (generation[column-2][row-1] == 'X') // Checks the left neighbor of the bottom right corner
          {
            counter++;
          }
          if (generation[column-1][row-2] == 'X') // Checks the top neighbor of the bottom right corner
          {
            counter++;
          }
          if (generation[column-2][row-2] == 'X') // Checks the top left neighbor of bottom right corner
          {
            counter++;
          }

          if (generation[0][0] == 'X') // Checks the top left of the grid
          {
            counter++;
          }

          if (generation[column-1][0] == 'X') // Checks the top right corner of grid
          {
            counter++;
          }
          if (generation[column-2][0] == 'X') // Checks the left of the top right corner of the grid
          {
            counter++;
          }
          if (generation[0][row-1] == 'X') // Checks the bottom left of the grid
          {
            counter++;
          }
          if (generation[0][row-2] == 'X') // Checks the top of the bottom left of the grid
          {
            counter++;
          }
        }


        // Finish if the center of the grid is called on
      }


      // This is what should be implemented with counter


      counter = 0;
    }
  }
}
