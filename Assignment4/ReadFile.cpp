#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "ReadFile.h"

ReadFile::ReadFile()
{
  fileName = "\0";
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
}

ReadFile::ReadFile(string file)
{
  fileName = file;
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
}

ReadFile::~ReadFile()
{

}

void ReadFile::readFromFile(string file)
{
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
    int lineCounter = 0;

    while (getline(inFS, line))
    {
      ++lineCounter;

      if (lineCounter == 1)
      {
        int numWindow = stoi(line);
        setWindowsOpen(numWindow);
      }

      if (lineCounter == 2)
      {
        int numTime = stoi(line);
        setTime(numTime);
      }

      if (lineCounter == 3)
      {
        int numStudents = stoi(line);
        setStudentsArrive(numStudents);
      }

      if (lineCounter > 3) // && getStudentsArrive() )
      {
        return;
      }
    }
  }
}

// Setters for the private variables
void ReadFile::setFileName(string fileName)
{
  this->fileName = fileName;
}

void ReadFile::setWindowsOpen(int windowsOpen)
{
  this->windowsOpen = windowsOpen;
}

void ReadFile::setTime(int time)
{
  this->time = time;
}

void ReadFile::setStudentsArrive(int studentsArrive)
{
  this->studentsArrive = studentsArrive;
}

void ReadFile::setMinAtWindow(int minAtWindow)
{
  this->minAtWindow = minAtWindow;
}


// Getters for all private variables
string ReadFile::getFileName()
{
  return fileName;
}

int ReadFile::getWindowsOpen()
{
  return windowsOpen;
}

int ReadFile::getTime()
{
  return time;
}

int ReadFile::getStudentsArrive()
{
  return studentsArrive;
}

int ReadFile::getMinAtWindow()
{
  return minAtWindow;
}
