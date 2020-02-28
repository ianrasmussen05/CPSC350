// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// main.cpp

#include "GameOfLife.h"

int main(int argc, char** argv)
{
  GameOfLife *life = new GameOfLife();

  string userInput = "\0";
  cout << "Do you wish to provide a map file(type 'file') or have it randomly generated(type 'random')? ";
  cin >> userInput;

  for (int i = 0; i < userInput.size(); ++i)
  {
    userInput[i] = tolower(userInput[i]);
  }

  if (userInput == "file")
  {
    string fName = "\0";

    cout << "Enter the file name: ";
    cin >> fName;

    ifstream inFS;

    inFS.open(fName);

    if (!inFS.is_open())
    {
      cout << "Could not open file " << fName << "." << endl;
      return 1;
    }
    else
    {

    }
  }
  else if (userInput == "random")
  {
    int userInputRow = 0;
    int userInputColumn = 0;
    double userInputDensity = 0.0;

    life->input(userInputRow, userInputColumn, userInputDensity);

    life->firstGeneration(userInputRow, userInputColumn, userInputDensity);
  }
  else
  {
    cout << "You entered an invalid command..." << endl;
    return 1;
  }

  delete life;

  return 0;
}
