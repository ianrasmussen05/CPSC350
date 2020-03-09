// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// ClassicMode.h

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

class ClassicMode
{
private:
  int row;
  int column;
  double density;

public:
  ClassicMode(); // Constructor
  ClassicMode(int row, int column); // Overloaded Constructor
  ~ClassicMode(); // Destructor

  void generateGrid();
  void countNeighbors();

  bool isEmpty();

  // Generations
  char **generation;
  char **nextGeneration;
};
