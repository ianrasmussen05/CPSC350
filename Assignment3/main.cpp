// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 3
// main.cpp

#include "SyntaxCheck.h"

int main (int argc, char **argv)
{
  if (argc >= 2) // Checks if the user entered 2 or more console inputs
  {
    SyntaxCheck *check = new SyntaxCheck();

    string fileName = argv[1];

    check->readFile(fileName);

    delete check;
  }
  else // If the user didn't enter enough inputs in the console, it exits the program 
  {
    cout << "Please enter the correct console input." << endl;
    exit(0);
  }

  return 0;
}
