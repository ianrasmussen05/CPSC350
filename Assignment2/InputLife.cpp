// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// InputLife.cpp

#include "InputLife.h"

 // Constructor
InputLife::InputLife()
{
  row = 0;
  column = 0;
  density = 0.0;
  fileName = "\0";
}

// Destructor
InputLife::~InputLife()
{

}

void InputLife::FileOrConsole()
{
  string userInput = "\0";
  cout << "Do you wish to provide a map file(type 'file') or have it randomly generated(type 'random')? ";
  cin >> userInput;

  for (int i = 0; i < userInput.size(); ++i)
  {
    userInput[i] = tolower(userInput[i]);
  }

  while (true)
  {
    if (userInput == "file")
    {
      ReadFile();

      break;
    }
    else if (userInput == "random")
    {
      validInputs();

      break;
    }
    else
    {
      cout << "Invalid input..." << endl;
      continue;
    }
  }
}

// Reads from a file, checking the rows and columns in the file
void InputLife::ReadFile()
{
  string userFile = "\0";
  cout << "Enter the name of the file: ";
  cin >> userFile;

  setFileName(userFile);

  ifstream inFS;

  inFS.open(fileName);

  if (!inFS.is_open())
  {
    cout << "Could not open file " << fileName << "." << endl;
  }
  else
  {

  }


  inFS.close();
}

void InputLife::validInputs()
{
  int userRow = 0;
  cout << "Enter the number of rows: ";
  cin >> userRow;

  while (userRow < 3 || userRow > 100)
  {
    cout << "Invalid input... Enter the number of rows: ";
    cin >> userRow;
  }
  if (userRow >= 3 && userRow <= 100)
  {
    setRow(userRow);
  }


  int userColumn = 0;
  cout << "Enter the number of columns: ";
  cin >> userColumn;

  while (userColumn < 3 || userColumn > 100)
  {
    cout << "Invalid input... Enter the number of columns: ";
    cin >> userColumn;
  }
  if (userColumn >= 3 && userColumn <= 100)
  {
    setColumn(userColumn);
  }


  double userDensity = 0.0;
  cout << "Enter the density from 0.0 to 1.0: ";
  cin >> userDensity;

  while (userDensity <= 0.0 || userDensity > 1.0)
  {
    cout << "Invalid input... Enter the density: ";
    cin >> userDensity;
  }
  if (userDensity > 0.0 && userDensity <= 1.0)
  {
    setDensity(userDensity);
  }
}



// Getters for all variables
int InputLife::getRow()
{
  return row;
}

int InputLife::getColumn()
{
  return column;
}

double InputLife::getDensity()
{
  return density;
}

string InputLife::getFileName()
{
  return fileName;
}


// Setters for all variables
void InputLife::setRow(int row)
{
  this->row = row;
}

void InputLife::setColumn(int column)
{
  this->column = column;
}

void InputLife::setDensity(double density)
{
  this->density = density;
}

void InputLife::setFileName(string fileName)
{
  this->fileName = fileName;
}
