// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// main.cpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "BinarySearchTree.h"
#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include "Simulation.h"

int main(int argc, char** argv)
{
  Simulation *sim = new Simulation();

  sim->setStudentFile("studentTable.txt"); // Set student file name to studentTable
  sim->setFacultyFile("facultyTable.txt"); // Set faculty file name to facultyTable

  sim->runProgram(); // Run entire program 

  delete sim;

  return 0;
}
