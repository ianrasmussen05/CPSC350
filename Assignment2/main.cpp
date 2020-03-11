// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 2
// main.cpp

#include "InputLife.h"
#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DoughnutMode.h"

int main(int argc, char** argv)
{
  string userInput = "\0";

  while (true)
  {
    InputLife *inputClass = new InputLife();

    cout << "What mode would you like to use ('Classic', 'Mirror', 'Doughnut'): ";
    cin >> userInput;

    for (int i = 0; i < userInput.size(); ++i)
    {
      userInput[i] = tolower(userInput[i]);
    }



    if (userInput == "classic")
    {
      cout << "Welcome to Classic Mode!" << endl;

      inputClass->FileOrConsole();

      int currRow = inputClass->getRow();
      int currColumn = inputClass->getColumn();
      double currDensity = inputClass->getDensity();

      ClassicMode *classic = new ClassicMode(currRow, currColumn, currDensity);

      classic->generateGridRandom();

      classic->printGrid(classic->getNextGeneration(), currRow, currColumn);

      delete classic;
    }
    else if (userInput == "mirror")
    {
      cout << "Welcome to Mirror Mode!" << endl;

      inputClass->FileOrConsole();

      int currRow = inputClass->getRow();
      int currColumn = inputClass->getColumn();
      double currDensity = inputClass->getDensity();

      MirrorMode *mirror = new MirrorMode(currRow, currColumn, currDensity);

      mirror->generateGridRandom();

      cout << endl;

      mirror->printGrid(mirror->getNextGeneration(), currRow, currColumn);

      delete mirror;
    }
    else if (userInput == "doughnut")
    {
      cout << "Welcome to Doughnut Mode!" << endl;

      inputClass->FileOrConsole();

      int currRow = inputClass->getRow();
      int currColumn = inputClass->getColumn();
      double currDensity = inputClass->getDensity();

      DoughnutMode *doughnut = new DoughnutMode(currRow, currColumn, currDensity);

      doughnut->generateGridRandom();

      cout << endl;

      doughnut->printGrid(doughnut->getNextGeneration(), currRow, currColumn);


      delete doughnut;
    }
    else
    {
      cout << "Invalid input... Please choose the correct mode." << endl;

    }



    cout << "Type 'exit' to exit program or 'continue' to run the program again." << endl;
    cin >> userInput;

    for (int i = 0; i < userInput.size(); ++i)
    {
      userInput[i] = tolower(userInput[i]);
    }

    if (userInput == "exit")
    {
      break;
    }
    else
    {
      continue;
    }

    userInput = "\0";
    delete inputClass;
  }

  return 0;
}
