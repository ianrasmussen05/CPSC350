#include <iostream>
#include <string>

using namespace std;

#include "Simulation.h"

int main(int argc, char **argv)
{
  Simulation *sim = new Simulation();

  if (argc < 2)
  {
    cout << "There are not enough parameters in the console..." << endl;
    return 0;
  }


  delete sim;

  return 0;
}
