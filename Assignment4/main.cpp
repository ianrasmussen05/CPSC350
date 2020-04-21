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
  Simulation *sim = new Simulation(argv[1]);
  Queue<int> *q = new Queue<int>(10);

  if (argc < 2)
  {
    cout << "There are not enough parameters in the console..." << endl;
    return 0;
  }

  sim->readFromFile();

  for (int i = 0; i < 2; ++i)
  {
    cout << sim->getList()->remove() << endl;
  }

  q->insert(5);
  q->insert(6);
  q->insert(10);

  for (int i = 0; i < q->getSize(); ++i)
  {
    if (q->peek() == NULL)
    {
      cout << "The rest of the array is empty" << endl;
      return 0;
    }
    cout << q->remove() << endl;
  }


  delete sim;
  delete q;

  return 0;
}
