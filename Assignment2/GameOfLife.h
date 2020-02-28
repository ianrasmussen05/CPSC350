// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// GameOfLife.h

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

class GameOfLife
{
public:
  GameOfLife(); // Constructor
  ~GameOfLife(); // Destructor

  void input(int &row, int &column, double &density);
  void firstGeneration(int row, int column, double density);

protected:

private:

};
