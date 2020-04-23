// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// main.cpp

#include <iostream>
#include <string>

using namespace std;

#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "Simulation.h"

int main(int argc, char **argv)
{
  // Checks to see if there are enough parameters in the console
  if (argc < 2)
  {
    cout << "There are not enough parameters in the console..." << endl;
    return 0;
  }

  Simulation *sim = new Simulation(argv[1]);

  sim->readFromFile(); // Read from the file inputed
  sim->runProgram(); // Runs simulation 


  delete sim;

  return 0;
}
