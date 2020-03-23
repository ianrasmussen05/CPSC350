// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 3
// SyntaxCheck.cpp

#include "SyntaxCheck.h"

// Default constructor that sets each member variable
SyntaxCheck::SyntaxCheck()
{
  stack = new GenStack<char>(); // Initialize the pointer of stack as a char array
  fileName = "\0"; // Sets file name to null
}

// Destructor that deletes the pointer stack array
SyntaxCheck::~SyntaxCheck()
{
  delete []stack;
}

// This function prompts the user if they would like to run the program again,
// asking them for the file name
void SyntaxCheck::inputFile()
{
  string userInput = "\0";
  cout << "Would you like the program to run again? (y/n)" << endl;
  cin >> userInput;

  // Sets the users input to all lower case letters to get rid of possible problems
  for (int i = 0; i < userInput.size(); ++i)
  {
    userInput[i] = tolower(userInput[i]);
  }

  // Checks the first letter of the userInput to see if they chose yes or no
  if (userInput[0] == 'y')
  {
    userInput = "\0";

    // User enters file name
    cout << "Enter the file name: ";
    cin >> userInput;

    setFile(userInput); // Sets the file name

    readFile(fileName); // Reads the file from function below
  }
  else // If the user doesn't want ot enter a new file, exits program
  {
    cout << "Exiting the program." << endl;
    exit(1);
  }
}

// This method checks from a file, that will then check to see if everything matches up
// with each curly bracket{}, each bracket[], and each parantheses(). Using the GenStack
// from another class will push and check each character in the file
void SyntaxCheck::readFile(string fileName)
{
  ifstream inFS;

  inFS.open(fileName); // Opens file

  if (!inFS.is_open()) // If the file doesn't open, program exits
  {
    cout << "Could not open file '" << fileName << "'." << endl;
    exit(0);
  }
  else // Program continues if file exists
  {




  }

  inFS.close(); // Close the file

  inputFile(); // Prompts the user if they want to read from another file 
}

// Getter for the file name
string SyntaxCheck::getFile()
{
  return fileName;
}

// Setter for the file name
void SyntaxCheck::setFile(string fileName)
{
  this->fileName = fileName;
}
