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
public:
  ClassicMode(); // Constructor
  ClassicMode(int row, int column, double density); // Overloaded Constructor
  ~ClassicMode(); // Destructor


private:
  int row;
  int column;
  double density;
};
