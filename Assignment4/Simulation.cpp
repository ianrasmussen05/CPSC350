// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Simulation.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "Simulation.h"

// The default constructor where I initialize all my variables
Simulation::Simulation()
{
  fileName = "\0";
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
  queue = new Queue<Student*>();
  list = new LinkedList<Student*>();
}

// The Overloaded construcotr where the parameter is the file name from the console
Simulation::Simulation(string file)
{
  fileName = file;
  windowsOpen = 0;
  time = 0;
  studentsArrive = 0;
  minAtWindow = 0;
  queue = new Queue<Student*>();
  list = new LinkedList<Student*>();
}

// Destructor
Simulation::~Simulation()
{
  delete queue;
  delete list;
  delete finalList;
  delete []window;
}

// This function is called to read from a file assuming the file has the right order of variables
void Simulation::readFromFile()
{
  string file = getFileName(); // Get filename from function

  ifstream inFS;

  inFS.open(file); // Open file

  if (!inFS.is_open()) // Check to see if the files opens properly
  {
    cout << "Could not open file '" << file << "'." << endl;
    exit(0);
  }
  else // Go on with function
  {
    string line = "\0"; // Sting that will have the content of each line
    int firstLine = 0; // First line number
    int lineCounter = 1; // Line counter starts at 1 because lines start at 1


    while (getline(inFS, line)) // Iterates through the rest of the lines in the file
    {
      if (firstLine == 0) // This will be true no matter what
      {
        setWindowsOpen(stoi(line)); // Set number of windows to the line

        window = new Window[getWindowsOpen()]; // Allocate new memory as an array for number of windows open

        // A for loop to assign each object in the array
        for (int i = 0; i < getWindowsOpen(); ++i)
        {
          window[i] = *new Window();
        }

        ++firstLine; // So it breaks out of this if statement for the rest of the function
      }
      else
      {
        if (lineCounter == 2) // The second line is the time at which the students get there
        {
          setTime(stoi(line)); // Set time
        }
        else if (lineCounter == 3) // The third line will be the number of students that arrive at that time
        {
          setStudentsArrive(stoi(line)); // Set the amount of students arriving

          // for loop to iterate how many students will be next
          for (int i = 0; i < getStudentsArrive(); ++i)
          {
            getline(inFS, line); // Goes to the next line

            Student *newStudent = new Student(stoi(line), getTime(), 0);
            list->insertBack(newStudent); // Insert the new student into a linked list
          }

          lineCounter = 1; // So it can start at the next time students arrive
        }
        else // In case it is a wrong input file
        {
          cout << "Error: Check your file..." << endl;
        }
      }

      ++lineCounter;
    }

    inFS.close();
  }
}

void Simulation::runProgram()
{
  int clockTime = 0; // Going to be the clock ticking in this case
  int firstWindowOpen = 0; // Integer representing the first available window
  finalList = new LinkedList<Student*>(); // The final list of the program to use for statistics
  ListNode<Student*> *curr; // Current listnode to be used for later
  int numOfStudents = list->getSize(); // Number of students in line


  while (finalList->getSize() < numOfStudents) // while the final list has less students than the original list keep iterating
  {

    // Gets information from file and makes sure the clockTime and arrival time are the same
    curr = list->front;
    while (curr != NULL)
    {
      if (curr->data->timeArrived == clockTime)
      {
        queue->insert(curr->data);
      }

      curr = curr->next;
    }


    // Allows the students to go to the first available window
    while (!allWindowsClosed() && !queue->isEmpty())
    {
      for (int i = 0; i < getWindowsOpen(); ++i)
      {
        if (window[i].currStudent == NULL) // If window is empyt
        {
          firstWindowOpen = i; // Assign first window open to the spot in array
          break;
        }
      }

      // Assign Student to first window
      Student *temp = queue->remove();
      // Assign the temp variables to the window
      window[firstWindowOpen].currStudent = new Student(temp->timeNeeded, temp->timeArrived, temp->waitTime);
      window[firstWindowOpen].currStudent->isInWindow = true; // It is true that the student is at a window

      //cout << window[firstWindowOpen].currStudent->waitTime << endl;
    }


    // Update wait time for students
    curr = list->front;
    while (curr != NULL)
    {
      // If the arrived time is the same or less than the minute and if the
      // student is not in a window already
      if (curr->data->isInWindow == false)
      {
        curr->data->waitTime++; // Increment wait time of student in line
      }

      curr = curr->next; // Goes to next node
    }


    // This is checking if the windows are idling or if they need to let students go
    for (int i = 0; i < getWindowsOpen(); ++i)
    {
      if (window[i].currStudent == NULL) // The window is idling, no Student
      {
        window[i].idleTime++;
      }
      else
      {
        window[i].currStudent->timeNeeded--;
        if (window[i].currStudent->timeNeeded == 0) // Student has no more minutes at window, must leave
        {
          Student *temp = window[i].currStudent;
          finalList->insertBack(temp); // insert student into the final list
          window[i].currStudent = NULL;
        }
      }
    }

    ++clockTime;
  }

  statistics();
}

void Simulation::statistics()
{
  // All the totals for each value that need to be printed out to user
  double meanStudentWait = 0.0;
  int medianStudentWait = 0;
  int longestStudentWait = 0;
  int numStudentsOverTen = 0;
  double meanWindowIdle = 0.0;
  int longestWindowIdle = 0;
  int windowsIdleOverFive = 0;

  // Sums or total of student wait and window idle
  int studentWaitTotal = 0;
  int windowIdleTotal = 0;


  int numOfStudents = list->getSize();
  int studentArr[numOfStudents];
  int count = 0;

  // This is finding the total students wait time, students waiting over ten minutes
  // and the longest waiting student
  while (!finalList->isEmpty())
  {
    studentArr[count] = finalList->removeFront()->waitTime;

    if (studentArr[count] > 10) // Checks to see if the student waited over 10 minutes
    {
      numStudentsOverTen++;
    }

    if (studentArr[count] > longestStudentWait) // Checks the longest waiting student
    {
      longestStudentWait = studentArr[count];
    }

    studentWaitTotal += studentArr[count];

    count++;
  }


  // Goes through the array of windows and adds the idle time to get the total idle time,
  // counts each time a window idles over 5 minutes, and finds the longest window idle
  for (int i = 0; i < getWindowsOpen(); ++i)
  {
    windowIdleTotal += window[i].idleTime;

    // Checks if wait time is over five, adds to counter
    if (window[i].idleTime > 5)
    {
      windowsIdleOverFive++;
    }

    // Checks if it is the largest window idle
    if (window[i].idleTime > longestWindowIdle)
    {
      longestWindowIdle = window[i].idleTime;
    }
  }

  // These next several lines are finding the median of students waiting
  int middle = 0;

  sort(studentArr, studentArr + numOfStudents); // https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
  middle = numOfStudents / 2;

  if (numOfStudents % 2 == 0) // There are a even number of students
  {
    medianStudentWait = (studentArr[middle] + studentArr[middle + 1]) / 2;
  }
  else
  {
    medianStudentWait = studentArr[middle];
  }


  // The mean for students wait
  meanStudentWait = (double)studentWaitTotal / numOfStudents;

  // The mean for windows idle
  meanWindowIdle = (double)windowIdleTotal / getWindowsOpen();


  // Printing out final Statistics
  cout << endl;
  cout << "FINAL STATISTICS" << endl;
  cout << endl;
  cout << "The mean student wait time: " << meanStudentWait << endl;
  cout << "The median student wait time: " << medianStudentWait << endl;
  cout << "The longest student wait time: " << longestStudentWait << endl;
  cout << "The number of students waiting over 10 minutes: " << numStudentsOverTen << endl;
  cout << "The mean window idle time: " << meanWindowIdle << endl;
  cout << "The longest window idle time: " << longestWindowIdle << endl;
  cout << "Number of windows idle for over 5 minutes: " << windowsIdleOverFive << endl;
  cout << endl;
}

// Returns true if all windows are open
bool Simulation::allWindowsOpen()
{
  for (int i = 0; i < getWindowsOpen(); ++i)
  {
    if (window[i].currStudent != NULL)
    {
      return false;
    }
  }

  return true;
}

// Returns true if all windows are closed
bool Simulation::allWindowsClosed()
{
  for (int i = 0; i < getWindowsOpen(); ++i)
  {
    if (window[i].currStudent == NULL)
    {
      return false;
    }
  }

  return true;
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

Queue<Student*> *Simulation::getQueue()
{
  return queue;
}

LinkedList<Student*> *Simulation::getList()
{
  return list;
}
