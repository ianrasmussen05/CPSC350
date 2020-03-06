// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// MirrorMode.h

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

class MirrorMode
{
private:
  int row;
  int column;
  double density;

public:
  MirrorMode();
  MirrorMode(int row, int column, double density);
  ~MirrorMode();

  void generateGrid();
  void countNeighbors();


  // Generations
  char **generation;
};
