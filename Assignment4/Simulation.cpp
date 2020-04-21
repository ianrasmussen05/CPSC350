// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Simulation.cpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "Simulation.h"


Simulation::Simulation()
{
  fileName = "\0";
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
  list = new Queue<Student*>();
}

Simulation::Simulation(string file)
{
  fileName = file;
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
  list = new Queue<Student*>();
}

Simulation::~Simulation()
{
  delete list;
  delete []window;
}

void Simulation::readFromFile()
{
  string file = getFileName();

  ifstream inFS;

  inFS.open(file);

  if (!inFS.is_open())
  {
    cout << "Could not open file '" << file << "'." << endl;
    exit(0);
  }
  else
  {
    string line = "\0";

    getline(inFS, line); // Gets the first line of the file
    setWindowsOpen(stoi(line)); // Sets how many lines are open from the first line

    window = new Window[windowsOpen]; // Allocate new memory as an array for number of windows open

    // A for loop to assign each object in the array
    for (int i = 0; i < windowsOpen; ++i)
    {
      window[i] = *new Window();
    }


    while (getline(inFS, line)) // Iterates through the rest of the lines in the file
    {
      setTime(stoi(line)); // Sets the time at which students arrive

      getline(inFS, line); // Goes to the next line
      setStudentsArrive(stoi(line)); // Sets the number of students arriving at that time above

      for (int i = 0; i < getStudentsArrive(); ++i)
      {
        getline(inFS, line); // Goes to the next line
        Student *newStudent = new Student(stoi(line), getTime());
        list->insert(newStudent);
      }
    }

    inFS.close();
  }
}

void Simulation::runProgram()
{

}

void Simulation::statistics()
{

}

// Setters for the private variables
void Simulation::setFileName(string fileName)
{
  this->fileName = fileName;
}

void Simulation::setWindowsOpen(int windowsOpen)
{
  this->windowsOpen = windowsOpen;
}

void Simulation::setTime(int time)
{
  this->time = time;
}

void Simulation::setStudentsArrive(int studentsArrive)
{
  this->studentsArrive = studentsArrive;
}

void Simulation::setMinAtWindow(int minAtWindow)
{
  this->minAtWindow = minAtWindow;
}

void *Simulation::setList(Queue<Student*> *newList)
{
  this->list = newList;
}


// Getters for all private variables
string Simulation::getFileName()
{
  return fileName;
}

int Simulation::getWindowsOpen()
{
  return windowsOpen;
}

int Simulation::getTime()
{
  return time;
}

int Simulation::getStudentsArrive()
{
  return studentsArrive;
}

int Simulation::getMinAtWindow()
{
  return minAtWindow;
}

Queue<Student*> *Simulation::getList()
{
  return list;
}
