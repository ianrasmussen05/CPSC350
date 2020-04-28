// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// Simulation.cpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "BinarySearchTree.h"
#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include "Simulation.h"

Simulation::Simulation()
{
  studentFile = "\0";
  facultyFile = "\0";
  studentTree = new BinarySearchTree<Student*>();
  facultyTree = new BinarySearchTree<Faculty*>();
}

Simulation::~Simulation()
{
  delete studentTree;
  delete facultyTree;
}

void Simulation::readStudentFile()
{

}

void Simulation::readFacultyFile()
{

}

void Simulation::printAllStudents()
{

}

void Simulation::printAllFaculty()
{

}

void Simulation::findStudent(int id)
{

}

void Simulation::findFaculty(int id)
{

}

void Simulation::printAdvisor(int id)
{

}

void Simulation::printAdvisees(int id)
{

}

void Simulation::addStudent()
{

}

void Simulation::deleteStudent(int id)
{

}

void Simulation::addFaculty()
{

}

void Simulation::deleteFaculty(int id)
{

}

void Simulation::changeAdvisor(int studentID, int facultyID)
{

}

void Simulation::removeAdvisee(int studentID, int facultyID)
{

}

void Simulation::rollBack()
{

}


// This is where all the functions are put into one method
void Simulation::runProgram()
{
  cout << "---------------Welcome to the School Database---------------" << endl;

  int userInput = 0;

  while (true)
  {
    cout << endl;
    cout << "1. Print all students in the database" << endl;
    cout << "2. Print all faculty in the database" << endl;
    cout << "3. Find student" << endl;
    cout << "4. Find faculty" << endl;
    cout << "5. Find advisor given the student ID" << endl;
    cout << "6. Find the advisees given the faculty ID" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor" << endl;
    cout << "12. Remove an advisee from a faculty member" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << endl;

    cout << "Enter a number: " << endl;
    cin >> userInput; // Put a try catch statement
    cout << endl;

    if (userInput == 1)
    {
      printAllStudents();
    }
    else if (userInput == 2)
    {
      printAllFaculty();
    }
    else if (userInput == 3)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      findStudent(userInput);
    }
    else if (userInput == 4)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      findFaculty(userInput);
    }
    else if (userInput == 5)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      printAdvisor(userInput);
    }
    else if (userInput == 6)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      printAdvisees(userInput);
    }
    else if (userInput == 7)
    {
      addStudent();
    }
    else if (userInput == 8)
    {
      cout << "Student ID number: ";
      cin >> userInput; // Try catch here

      deleteStudent(userInput);
    }
    else if (userInput == 9)
    {
      addFaculty();
    }
    else if (userInput == 10)
    {
      cout << "Faculty ID number: ";
      cin >> userInput; // Try catch here

      deleteFaculty(userInput);
    }
    else if (userInput == 11)
    {
      int userStudent = 0;
      int userFaculty = 0;

      cout << "Student ID number: ";
      cin >> userStudent; // Try catch here

      cout << "Faculty ID number: ";
      cin >> userFaculty; // Try catch here

      changeAdvisor(userStudent, userFaculty);
    }
    else if (userInput == 12)
    {
      int userStudent = 0;
      int userFaculty = 0;

      cout << "Student ID number: ";
      cin >> userStudent; // Try catch here

      cout << "Faculty ID number: ";
      cin >> userFaculty; // Try catch here

      removeAdvisee(userStudent, userFaculty);
    }
    else if (userInput == 13)
    {
      rollBack();
    }
    else if (userInput == 14)
    {
      cout << "Exiting program..." << endl;
      break;
    }
    else
    {
      cout << "ERROR: Enter a valid input..." << endl;
    }

    userInput = 0;
  }
}


// Getters
string Simulation::getStudentFile()
{
  return studentFile;
}

string Simulation::getFacultyFile()
{
  return facultyFile;
}

BinarySearchTree<Student*> *Simulation::getStudentTree()
{
  return studentTree;
}

BinarySearchTree<Faculty*> *Simulation::getFacultyTree()
{
  return facultyTree;
}
