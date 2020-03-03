// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// InputLife.cpp

#include "InputLife.h"

GameOfLife::GameOfLife()
{
  row = 0;
  column = 0;
  density = 0.0;
}

GameOfLife::~GameOfLife()
{
  delete myArray;
}

void GameOfLife::input(int &row, int &column, double &density)
{
  cout << "Enter the number of rows: ";
  cin >> row;

  cout << "Enter the number of columns: ";
  cin >> column;

  cout << "Enter the population density(0-1): ";
  cin >> density;
  while (density == 0.0 || density > 1)
  {
    cout << "Please enter a number above 0 and less than or equal to 1: ";
    cin >> density;
  }
}

void GameOfLife::firstGeneration(int row, int column, double density)
{
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {

    }
  }
}
