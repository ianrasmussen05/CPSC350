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
  InputLife *gol = new InputLife();

  gol->FileOrConsole();

  cout << gol->getRow() << endl;
  cout << gol->getColumn() << endl;
  cout << gol->getDensity() << endl;



  delete gol;

  return 0;
}
