// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// DoughnutMode.h

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

class DoughnutMode
{
private:
  int row;
  int column;
  double density;

public:
  DoughnutMode();
  DoughnutMode(int row, int column);
  DoughnutMode(int row, int column, double density);
  ~DoughnutMode();

  void generateGridRandom();
  void countNeighbors(char **grid, int row, int column);

  bool isEmpty(char **grid, int row, int column);
  void printGrid(char **grid, int row, int column);

  void setGeneration(char** grid);
  void setNextGeneration(char** grid);

  char **getGeneration();
  char **getNextGeneration();


  // Generations
  char **generation;
  char **nextGeneration;
};
