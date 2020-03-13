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

      if (inputClass->getFileName() == "\0") // Checks if the user chose the random selection
      {
        ClassicMode *classic = new ClassicMode(currRow, currColumn, currDensity);

        int gridCounter = 0;
        classic->generateGridRandom();
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        classic->setGeneration(classic->getNextGeneration());

        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n') // checks if user pressed enter key
        {
          while (cin.get() == '\n')
          {
            classic->countNeighbors(classic->getGeneration(), currRow, currColumn);
            classic->printGrid(classic->getGeneration(), currRow, currColumn);

            if (classic->isEmpty(classic->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            classic->setGeneration(classic->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete classic;
      }
      else // If the user chose the file path
      {
        ClassicMode *classic = new ClassicMode(currRow, currColumn);

        int gridCounter = 0;
        classic->generateGridFile(); // Still need to implement this
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        classic->setGeneration(classic->getNextGeneration());

        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n') // Checks if user presses the enter key
        {
          while (cin.get() == '\n')
          {
            classic->countNeighbors(classic->getGeneration(), currRow, currColumn);
            classic->printGrid(classic->getGeneration(), currRow, currColumn);

            if (classic->isEmpty(classic->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            classic->setGeneration(classic->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete classic;
      }
    }
    else if (userInput == "mirror") // This is the mirror functions
    {
      cout << "Welcome to Mirror Mode!" << endl;

      inputClass->FileOrConsole();

      int currRow = inputClass->getRow();
      int currColumn = inputClass->getColumn();
      double currDensity = inputClass->getDensity();

      if (inputClass->getFileName() == "\0") // Checks if the user chose the random selection
      {
        MirrorMode *mirror = new MirrorMode(currRow, currColumn, currDensity);

        int gridCounter = 0;
        mirror->generateGridRandom();
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        mirror->setGeneration(mirror->getNextGeneration());


        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n')
        {
          while (cin.get() == '\n')
          {
            mirror->countNeighbors(mirror->getGeneration(), currRow, currColumn);
            mirror->printGrid(mirror->getGeneration(), currRow, currColumn);

            if (mirror->isEmpty(mirror->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            mirror->setGeneration(mirror->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete mirror;
      }
      else // if the user chose the file path
      {
        MirrorMode *mirror = new MirrorMode(currRow, currColumn);

        int gridCounter = 0;
        mirror->generateGridFile(); // Still need to implement this
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        mirror->setGeneration(mirror->getNextGeneration());


        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n')
        {
          while (cin.get() == '\n')
          {
            mirror->countNeighbors(mirror->getGeneration(), currRow, currColumn);
            mirror->printGrid(mirror->getGeneration(), currRow, currColumn);

            if (mirror->isEmpty(mirror->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            mirror->setGeneration(mirror->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete mirror;
      }
    }
    else if (userInput == "doughnut")
    {
      cout << "Welcome to Doughnut Mode!" << endl;

      inputClass->FileOrConsole();

      int currRow = inputClass->getRow();
      int currColumn = inputClass->getColumn();
      double currDensity = inputClass->getDensity();

      if (inputClass->getFileName() == "\0") // Checks if the user chose the random selection
      {
        DoughnutMode *doughnut = new DoughnutMode(currRow, currColumn, currDensity);

        int gridCounter = 0;
        doughnut->generateGridRandom();
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        doughnut->setGeneration(doughnut->getNextGeneration());


        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n')
        {
          while (cin.get() == '\n')
          {
            doughnut->countNeighbors(doughnut->getGeneration(), currRow, currColumn);
            doughnut->printGrid(doughnut->getGeneration(), currRow, currColumn);

            if (doughnut->isEmpty(doughnut->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            doughnut->setGeneration(doughnut->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete doughnut;
      }
      else
      {
        DoughnutMode *doughnut = new DoughnutMode(currRow, currColumn);

        int gridCounter = 0;
        doughnut->generateGridFile(); // Still need to implement this
        gridCounter++;
        cout << "Generation " << gridCounter << endl;
        doughnut->setGeneration(doughnut->getNextGeneration());


        cout << "Press enter to do another grid." << endl;

        if (cin.get() == '\n')
        {
          while (cin.get() == '\n')
          {
            doughnut->countNeighbors(doughnut->getGeneration(), currRow, currColumn);
            doughnut->printGrid(doughnut->getGeneration(), currRow, currColumn);

            if (doughnut->isEmpty(doughnut->getGeneration(), currRow, currColumn))
            {
              cout << "The generation is empty." << endl;
              break;
            }

            doughnut->setGeneration(doughnut->getNextGeneration());

            gridCounter++;
            cout << "Generation " << gridCounter << endl;
          }
        }
        else
        {
          cout << "Ending program." << endl;
        }

        gridCounter = 0;

        delete doughnut;
      }
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
