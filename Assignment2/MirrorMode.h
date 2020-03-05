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
public:
  MirrorMode();
  MirrorMode(int row, int column, double density);
  ~MirrorMode();


private:
  int row;
  int column;
  double density;
};
