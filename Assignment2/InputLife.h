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
#include <vector>

using namespace std;

class InputLife
{
private:
  // The basic variables needed for input
  int row;
  int column;
  double density;
  string fileName;

public:
  InputLife(); // Constructor
  ~InputLife(); // Destructor

  // Need this to be where the user inputs
  void FileOrConsole();
  void CheckFile();
  void gridFromFile(char **grid, string fileName);

  // This is making sure the inputs are valid
  void validInputs();
  bool isRandom();
  bool isFile();

  // Getters
  int getRow();
  int getColumn();
  double getDensity();
  string getFileName();
  char **getGeneration();

  // Setters
  void setRow(int row);
  void setColumn(int column);
  void setDensity(double density);
  void setFileName(string fileName);
  void setGeneration(char **grid);

  char **generation;
};
