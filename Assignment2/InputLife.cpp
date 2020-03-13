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
  delete generation;
}

// This function is called on to make the user have input
void InputLife::FileOrConsole()
{
  string userInput = "\0";
  cout << "Do you wish to provide a map file (type 'file') or have it randomly generated(type 'random')? ";
  cin >> userInput;

  for (int i = 0; i < userInput.size(); ++i)
  {
    userInput[i] = tolower(userInput[i]);
  }

  while (true)
  {
    if (userInput == "file")
    {
      CheckFile();
      isFile();

      break;
    }
    else if (userInput == "random")
    {
      validInputs();
      isRandom();
      fileName = "\0";

      break;
    }
    else
    {
      cout << "Invalid input..." << endl;
      continue;
    }
  }
}

// Reads from a file, checking if the rows and columns in the file are valid numbers
void InputLife::CheckFile()
{
  string userFile = "\0";

  while (true)
  {
    string line;

    cout << "Enter the name of the file: ";
    cin >> userFile;

    ifstream inFS;

    inFS.open(userFile);

    if (!inFS.is_open())
    {
      cout << "Could not open file " << userFile << "." << endl;
    }
    else
    {
      int rowCounter = 0;
      int columnCounter = 0;

      vector<char> gridArray;

      while (getline(inFS, line))
      {
        for (int i = 0; i < line.size()-1; ++i)
        {
          rowCounter++;
          gridArray.push_back(line[i]);
        }
        columnCounter++;
      }

      rowCounter /= columnCounter;


      if (rowCounter < 3 || rowCounter > 100)
      {
        cout << "Invalid input. Please enter another file.";
      }
      else if (columnCounter < 3 || columnCounter > 100)
      {
        cout << "Invalid input. Please enter another file.";
      }
      else
      {
        setColumn(columnCounter);
        setRow(rowCounter);
        setFileName(userFile);

        generation = new char *[column];

        for (int i = 0; i < column; ++i)
        {
          generation[i] = new char[row];
        }

        for (int i = 0; i < column; ++i)
        {
          for (int j = 0; j < row; ++j)
          {
            generation[i][j] = gridArray.at(0);
            gridArray.erase(gridArray.begin());
          }
        }

        setGeneration(generation);

        break;
      }
    }
    inFS.close();
  }
}

// Checks to see if the user had valid inputs
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


// Boolean functions that is always true
bool InputLife::isRandom()
{
  return true;
}

bool InputLife::isFile()
{
  return true;
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

char** InputLife::getGeneration()
{
  return generation;
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

void InputLife::setGeneration(char **grid)
{
  generation = grid;
}
