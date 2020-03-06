// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// MirrorMode.cpp

#include "MirrorMode.h"
#include "InputLife.h"

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
  delete generation;
}

void MirrorMode::generateGrid()
{

}

void MirrorMode::countNeighbors()
{
  int counter = 0;

  // Originally I wanted to do row then column, but I messed up too far and I switched the values
  // in the nested for loop
  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      char topLeftCorner = generation[0][0];
      char topRightCorner = generation[column-1][0];
      char bottomLeftCorner = generation[0][row-1];
      char bottomRightCorner = generation[column-1][row-1];

      // The next if statements check to see if its a corner
      // Checks to see if it is at the top left corner
      if (generation[i][j] == topLeftCorner)
      {
        if (topLeftCorner == 'X')
        {
          counter += 3;
        }
        if (generation[1][0] == 'X') // Checks the right spot from the left corner
        {
          counter += 2;
        }
        if (generation[0][1] == 'X') // Checks the bottom spot from the left corner
        {
          counter += 2;
        }
        if (generation[1][1] == 'X') // Checks the bottom right spot from left corner
        {
          counter++;
        }
      }
      // Checks to see if it is at the top right corner
      if (generation[i][j] == topRightCorner)
      {
        if (topRightCorner == 'X')
        {
          counter += 3;
        }
        if (generation[column-2][0] == 'X') // Checks the left of the right corner
        {
          counter += 2;
        }
        if (generation[column-1][1] == 'X') // Chekcs the bottom of the right corner
        {
          counter += 2;
        }
        if (generation[column-2][1]) // Checks the bottom left spot of the right corner
        {
          counter++;
        }
      }
      // Checks to see if it is at the bottom left corner
      if (generation[i][j] == bottomLeftCorner)
      {
        if (bottomLeftCorner == 'X')
        {
          counter += 3;
        }
        if (generation[1][row-1] == 'X') // Checks the right spot from the bottom left corner
        {
          counter += 2;
        }
        if (generation[0][row-2] == 'X')
        {
          counter += 2;
        }
        if (generation[1][row-2] == 'X')
        {
          counter++;
        }
      }
      // Checks to see if it is at the bottom right corner
      if (generation[i][j] == bottomRightCorner)
      {
        if (bottomRightCorner == 'X')
        {
          counter += 3;
        }
        if (generation[column-1][row-2] == 'X') // Checks the right of the spot
        {
          counter += 2;
        }
        if (generation[column-2][row-1] == 'X') // Checks the top of the spot
        {
          counter += 2;
        }
        if (generation[column-2][row-2] == 'X') // Checks the top left of the spot
        {
          counter++;
        }
      }

      char leftBorder = generation[0][j];
      char topBorder = generation[i][0];
      char rightBorder = generation[column-1][j];
      char bottomBorder = generation[i][row-1];

      // Checking the left border of the grid
      if ((generation[i][j] == leftBorder) && (leftBorder != (topLeftCorner || bottomLeftCorner)))
      {
        if (generation[i][j] == 'X') // Checks to see if value is X to add from the mirror rules
        {
          counter++;
        }
        if (generation[i][j-1] == 'X') // Checks the top spot
        {
          counter += 2;
        }
        if (generation[i][j+1] == 'X') // Checks the bottom spot
        {
          counter += 2;
        }
        if (generation[i+1][j] == 'X') // Checks the right spot
        {
          counter++;
        }
        if (generation[i+1][j-1] == 'X') // Checks top right spot
        {
          counter++;
        }
        if (generation[i+1][j+1] == 'X') // Checks bottom right spot
        {
          counter++;
        }
      }

      // Checking the top border of the grid
      if ((generation[i][j] == topBorder) && (topBorder != (topLeftCorner || topRightCorner)))
      {
        if (generation[i][j] == 'X') // Checks to see if spot has X and adds to counter because of mirror
        {
          counter++;
        }
        if (generation[i-1][j] == 'X') // Checks the left spot
        {
          counter += 2;
        }
        if (generation[i+1][j] == 'X') // Checks the right spot
        {
          counter += 2;
        }
        if (generation[i][j+1] == 'X') // Checks the bottom spot
        {
          counter++;
        }
        if (generation[i-1][j+1] == 'X') // Checks the bottom left spot
        {
          counter++;
        }
        if (generation[i+1][j+1] == 'X') // Checks teh bottom right spot
        {
          counter++;
        }
      }

      // Checking the right border of the grid
      if ((generation[i][j] == rightBorder) && (rightBorder != (topRightCorner || bottomRightCorner)))
      {
        if (generation[i][j] == 'X') // Checks to see if spot has X and adds to counter because of mirror mode
        {
          counter++;
        }
        if (generation[column-1][j-1] == 'X') // Checks the top spot
        {
          counter += 2;
        }
        if (generation[column-1][j+1] == 'X') // Checks the bottom spot
        {
          counter += 2;
        }
        if (generation[column-2][j] == 'X') // Checks the left spot
        {
          counter++;
        }
        if (generation[column-2][j-1] == 'X') // Checks the top left spot
        {
          counter++;
        }
        if (generation[column-2][j+1] == 'X') // Checks the bottom left spot
        {
          counter++;
        }
      }

      // Checking the bottom border of the grid
      if ((generation[i][j] == bottomBorder) && (bottomBorder != (bottomLeftCorner || bottomRightCorner)))
      {
        if (generation[i][j] == 'X') // Checks to see if spot has X and adds to counter because of mirror mode
        {
          counter++;
        }
        if (generation[i-1][row-1] == 'X') // Checks the left spot
        {
          counter += 2;
        }
        if (generation[i+1][row-1] == 'X') // Checks the right spot
        {
          counter +=2;
        }
        if (generation[i][row-2] == 'X') // Checks the top spot
        {
          counter++;
        }
        if (generation[i-1][row-2] == 'X') // Checks the top left spot
        {
          counter++;
        }
        if (generation[i+1][row-2] == 'X') // Checks the top right spot
        {
          counter++;
        }
      }

      if (generation[i][j] != (leftBorder || topBorder || rightBorder || bottomBorder || topLeftCorner || topRightCorner || bottomLeftCorner || bottomRightCorner))
      {
        // Checks the normal neighbors
        if (generation[i-1][j] == 'X') // Checks the left neighbor
        {
          counter++;
        }
        if (generation[i+1][j] == 'X') // Checks the right neighbor
        {
          counter++;
        }
        if (generation[i][j-1] == 'X') // Checks the top neighbor
        {
          counter++;
        }
        if (generation[i][j+1] == 'X') // Checks the bottom neighbor
        {
          counter++;
        }

        // Checks the diagnal neighbors
        if (generation[i-1][j-1] == 'X') // Checks the top left neighbor
        {
          counter++;
        }
        if (generation[i+1][j-1] == 'X') // Checks the top right neighbor
        {
          counter++;
        }
        if (generation[i-1][j+1] == 'X') // Checks the bottom left neighbor
        {
          counter++;
        }
        if (generation[i+1][j+1] == 'X') // Checks the bottom right neighbor
        {
          counter++;
        }
      }


      // Do something with the counter here

      counter = 0;
    }
  }
}
