// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// InputLife.h

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

class InputLife
{
public:
  InputLife(); // Constructor
  ~InputLife(); // Destructor

  // Need this to be where the user inputs
  void FileOrConsole();
  void ReadFile();

  // This is making sure the inputs are valid
  void validInputs();

  // Getters
  int getRow();
  int getColumn();
  double getDensity();
  string getFileName();

  // Setters
  void setRow(int row);
  void setColumn(int column);
  void setDensity(double density);
  void setFileName(string fileName);

  // All the variables used for input
  int row;
  int column;
  double density;
  string fileName;
};
